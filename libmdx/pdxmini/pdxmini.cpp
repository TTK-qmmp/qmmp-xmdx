#include "pdxmini.h"

#include <math.h>
#include <stdint.h>
#include <string.h>

#ifdef _WIN32
#include <winsock2.h>
#else
#include <arpa/inet.h>
#endif

#define PDX_NUM_SAMPLES 96

struct PDXSample
{
  uint32_t offset;
  uint32_t length;
};

// ADPCM conversion code adapted from MAME
struct ADPCMDecoder
{
  int diff_lookup[49 * 16];
  uint8_t output_bits;          // output_12bits ? 12 : 10
  int32_t signal;
  int32_t step;
  uint8_t signal_gain;

  ADPCMDecoder(uint8_t outputBits = 16, uint8_t signalGain = 4)
  {
    output_bits = outputBits;
    signal_gain = signalGain;
    compute_tables();
  }

  void decode(uint8_t* input, uint32_t numSamples, short* output)
  {
    uint8_t nibble_shift = 0;
    signal = -2;
    step   = 0;

    for(uint32_t curSmpl = 0; curSmpl < numSamples; curSmpl++)
    {
      // Compute the new amplitude and update the current step */
      const uint8_t nibble = (input[curSmpl / 2] >> nibble_shift) & 0x0F;
      nibble_shift   ^= 4;
      output[curSmpl] = clock(nibble);
    }
  }

  void compute_tables(void)
  {
    // nibble to bit map
    static const int nbl2bit[16][4] = {
      { 1, 0, 0, 0}, { 1, 0, 0, 1}, { 1, 0, 1, 0}, { 1, 0, 1, 1},
      { 1, 1, 0, 0}, { 1, 1, 0, 1}, { 1, 1, 1, 0}, { 1, 1, 1, 1},
      {-1, 0, 0, 0}, {-1, 0, 0, 1}, {-1, 0, 1, 0}, {-1, 0, 1, 1},
      {-1, 1, 0, 0}, {-1, 1, 0, 1}, {-1, 1, 1, 0}, {-1, 1, 1, 1}
    };

    // loop over all possible steps
    for(int step = 0; step <= 48; step++)
    {
      // compute the step value
      const int stepval = (int)floor(16.0 * pow(11.0 / 10.0, (double)step));
      // loop over all nibbles and compute the difference
      for(int nib = 0; nib < 16; nib++)
      {
        diff_lookup[step * 16 + nib] = nbl2bit[nib][0] *
                                       (stepval     * nbl2bit[nib][1] +
                                        stepval / 2 * nbl2bit[nib][2] +
                                        stepval / 4 * nbl2bit[nib][3] +
                                        stepval / 8);
      }
    }
  }

  int32_t clock(uint8_t nibble)
  {
    const int32_t max            = (1 << (output_bits - 1)) - 1;
    const int32_t min            = -(1 << (output_bits - 1));
    const int     index_shift[8] = { -1, -1, -1, -1, 2, 4, 6, 8 };

    signal += diff_lookup[step * 16 + (nibble & 15)];

    // clamp to the maximum
    if (signal > max)
      signal = max;
    else if (signal < min)
      signal = min;

    // adjust the step size and clamp
    step += index_shift[nibble & 7];
    if (step > 48)
      step = 48;
    else if (step < 0)
      step = 0;

    // return the signal scaled up to 32767
    // return signal << 4;
    int32_t final = signal << signal_gain;
    if (final < -0x8000)
      final = -0x8000;
    else if (final > 0x7FFF)
      final = 0x7FFF;
    return final;
  }
};


PDXMini::PDXMini()
{
  file    = nullptr;
  samples = new PDXSample[PDX_NUM_SAMPLES];
  offset  = 0;
  bsize   = 0;
  buffer  = nullptr;
}

PDXMini::~PDXMini()
{
  if(file)
  {
    fclose(file);
  }

  delete[] samples;
  delete[] buffer;
}

bool PDXMini::open(const char* filename)
{
  file = fopen(filename, "rb");
  if(!file)
  {
    return false;
  }

  for(int i = 0; i < PDX_NUM_SAMPLES; i++)
  {
    samples[i].offset = readBigUint32();
    samples[i].length = readBigUint32();

    const uint32_t length = samples[i].length;
    if(length > 0)
    {
      bsize += length * 2;
    }
  }

  buffer = new short[bsize];

  ADPCMDecoder decoder;
  for(int i = 0; i < PDX_NUM_SAMPLES; i++)
  {
    const uint32_t length = samples[i].length;
    if(length > 0)
    {
      uint8_t* data = new uint8_t[length];
      fseek(file, samples[i].offset, SEEK_SET);
      fread(data, 1, length, file);
      decoder.decode(data, length * 2, buffer + length * 2);
      delete[] data;
    }
  }
  return true;
}

int PDXMini::render(char* data)
{
  if(offset > bsize)
  {
    return 0;
  }

  const int size = sizeof(short) * 1024;
  memcpy(data, buffer + offset, size);
  offset += 1024;
  return size;
}

int PDXMini::length() const
{
  return bsize / 2 / 2 / sampleRate() * 1000;
}

int PDXMini::sampleRate() const
{
  return 8000;
}

unsigned int PDXMini::readBigUint32()
{
  unsigned int v;
  fread(&v, 1, sizeof(v), file);
  return ntohl(v);
}
