// MucomModule
// BouKiCHi 2019

#ifndef _MUCOM_MODULE_H_
#define _MUCOM_MODULE_H_

class MucomTag;
class Fade;
class CMucom;

class MucomModule
{
public:
  MucomModule();
  ~MucomModule();

  bool OpenMemory(uint8_t* data, int size, bool mub);

  void SetRate(int rate);
  void SetPCM(const char* file);
  void SetVoice(const char* file);
  void SetVolume(double vol);

  int GetRate();

  /// <summary>
  /// フェーダー使用？
  /// </summary>
  void UseFader(bool enable);

  /// <summary>
  /// デフォルトの曲秒数
  /// </summary>
  void SetDefaultLength(int length);

  /// <summary>
  /// シーク(秒数) 実験版
  /// </summary>
  void Seek(int pos);

  /// <summary>
  /// 再生位置(秒数)
  /// </summary>
  int GetPosition();

  /// <summary>
  /// 終了？
  /// </summary>
  bool IsEnd();

  /// <summary>
  /// 曲の長さ(秒数) (#timeタグ内容 or デフォルト値)
  /// </summary>
  int GetLength();

  /// <summary>
  /// タグ取得
  /// </summary>
  MucomTag* tag;

  /// <summary>
  /// レンダリング (frames = フレーム数、実際のバイト数は*4 (4=2ch*16bit))
  /// </summary>
  void Mix(short* buffer, int frames);

  void Skip();

  bool Play();
  void Close();

private:

  void LoadTag();

  int GetLengthFromTag();

  void LoadSongTag(const char* songFilename);

  int defaultLength;

  int length;

  double volume;
  bool   enableFade;

  Fade* fade;

  void FreeMucom();

  CMucom* mucom;

  const char* pcmfile;
  const char* voicefile;
  const char* outfile;
  int         audioRate;

  int seekPosition;

  int driverMode;
  int cmpopt;

  int playedFrames;

  bool playing;
};

#endif

