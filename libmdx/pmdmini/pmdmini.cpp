#include "pmdwin/pmdwin.h"
#include "pmdmini.h"

#include <string.h>

//
// path splitter
//
static int pmd_split_dir(const char* file, char* dir)
{
  char* p;
  int   len = 0;

  p = strrchr((char*)file, '/');

  if ( p )
  {
    len = (int)( p - file );
    strncpy (dir, file, len);
  }
  dir[ len ] = 0;

  return len;
}

PMDMini::PMDMini()
{
}

//
// 初期化
//
void PMDMini::pmd_init(void)
{
  char* current_dir = (char *)("./");

  if(pmdworks == nullptr)
  {
    pmdworks = new PMDWIN;
    pmdworkm = new PMDWIN;
  }

  pmdworks->init(current_dir);
  pmdworks->setpcmrate(SOUND_55K);

  pmdworkm->init(current_dir);

  pmd_length = 0;
  pmd_loop   = 0;
}


//
// 　周波数設定
//
void PMDMini::pmd_setrate(int freq)
{
  pmdworks->setpcmrate(freq);
}

//
// ファイルチェック
//
int PMDMini::pmd_is_pmd(const char* file)
{
  int           size;
  unsigned char header[3];

  FILE* fp;

  fp = fopen(file, "rb");

  if (!fp)
    return 0;

  size = (int)fread(header, 1, 3, fp);

  fclose(fp);


  if (size != 3)
    return 0;

  if (header[0] > 0x0f)
    return 0;

  if (header[1] != 0x18 && header[1] !=0x1a )
    return 0;

  if (header[2] && header[2] != 0xe6)
    return 0;

  return 1;
}

//
// エラーであれば0以外を返す
//
int PMDMini::pmd_play(const char* file, char* pcmdir)
{
  char dir[2048];

  char* path[4];
  char* current_dir = (char *)"./";

  if ( !pmd_is_pmd (file) )
    return 1;

  strcpy (pmd_file, file);

  if ( pmd_split_dir(file, dir) > 0 )
  {
    path[0] = dir;
    path[1] = pcmdir;
    path[2] = current_dir;
    path[3] = NULL;
  }
  else
  {
    path[0] = current_dir;
    path[1] = pcmdir;
    path[2] = NULL;
  }

  pmdworks->setpcmdir(path);

  // get song length in sec
  if (!pmdworkm->getlength(pmd_file, &pmd_length, &pmd_loop))
  {
    pmd_length = 0;
    pmd_loop   = 0;
  }

  pmd_title[0] = 0;
  pmd_compo[0] = 0;

  pmdworks->fgetmemo3(pmd_title, pmd_file, 1);
  pmdworks->fgetmemo3(pmd_compo, pmd_file, 2);

  pmdworks->music_load(pmd_file);
  pmdworks->music_start();
  return 0;
}

//
// トラック数
//
int PMDMini::pmd_get_tracks(void)
{
  return NumOfAllPart;
}

//
// 現在のノート
//
void PMDMini::pmd_get_current_notes(int* notes, int len)
{
  int i = 0;

  for ( i = 0; i < len; i++ )
    notes[i] = -1;

  if ( !pmdworks->getopenwork() )
    return;

  for ( i = 0; i < len; i++ )
  {
    int data = pmdworks->getopenwork()->MusPart[i]->onkai;

    if (data == 0xff)
      notes[i] = -1;
    else
      notes[i] = data;
  }
}

int PMDMini::pmd_length_sec(void)
{
  return pmd_length / 1000;
}

int PMDMini::pmd_loop_sec(void)
{
  return pmd_loop / 1000;
}

void PMDMini::pmd_renderer(short* buf, int len)
{
  pmdworks->getpcmdata(buf, len);
}

void PMDMini::pmd_stop(void)
{
  pmdworks->music_stop();
}

void PMDMini::pmd_get_title(char* dest)
{
  strcpy(dest, pmd_title);
}

void PMDMini::pmd_get_compo(char* dest)
{
  strcpy(dest, pmd_compo);
}
