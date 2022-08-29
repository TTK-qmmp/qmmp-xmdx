#ifndef __MDXMini_H__
#define __MDXMini_H__

typedef struct
{
  void* mdx2151;
  void* mdxmml_ym2151;
  void* pcm8;
  void* ym2151_c;
} songdata;

#include "mdx.h"

typedef struct
{
  int samples;
  int channels;
  MDX_DATA* mdx;
  PDX_DATA* pdx;
  void* self;
  songdata* songdata;
  int nlg_tempo;
} MDXMini;

#include "pcm8.h"

#define MDX_FREQ (PCM8_MASTER_PCM_RATE)

void mdx_set_rate(int freq);
void mdx_set_dir(MDXMini* data, char* dir);
int  mdx_open(MDXMini* data, const char* filename, char* pcmdir);
void mdx_close(MDXMini* data);
void mdx_disp_info(MDXMini* data);

int  mdx_next_frame(MDXMini* data);
int  mdx_frame_length(MDXMini* data);
void mdx_make_buffer(MDXMini* data, short* buf, int buffer_size);
int  mdx_calc_sample(MDXMini* data, short* buf, int buffer_size);

void mdx_get_title(MDXMini* data, char* title);
int  mdx_get_length(MDXMini* data);
void mdx_set_max_loop(MDXMini* data, int loop);

int mdx_get_buffer_size(MDXMini* data);
int mdx_get_sample_size(MDXMini* data);

int  mdx_get_tracks(MDXMini* data);
void mdx_get_current_notes(MDXMini* data, int* notes, int len);

#endif

