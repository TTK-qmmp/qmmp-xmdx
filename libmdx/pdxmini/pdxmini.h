#ifndef __PDXMINI_H__
#define __PDXMINI_H__

#include <stdio.h>

struct PDXSample;

class PDXMini
{
public:
  PDXMini();
  ~PDXMini();

  bool open(const char* filename);
  int  render(char* data);

  int length() const;
  int sampleRate() const;

private:
  void         decoder();
  unsigned int readBigUint32();

  FILE*      file;
  PDXSample* samples;

  unsigned int tsize;
  unsigned int bsize;
  short*       buffer;
};

#endif
