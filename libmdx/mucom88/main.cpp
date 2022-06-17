#include <QCoreApplication>
#include "module/mucom_module.h"

#include <QFile>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MucomModule module;
    module.Close();
    // 設定
    module.SetRate(44100);

    QFile file("/home/greedysky/sampl2.muc");
    file.open(QFile::ReadOnly);
    QByteArray data = file.readAll();
    module.OpenMemory((uchar*)data.constData(), file.size(), file.fileName().toLocal8Bit().constData());
    module.UseFader(true);
   qDebug() << module.Play() << module.IsEnd() << module.GetLength();

   int frames = 1024;
   char bytes[1024 *4];
   while(!module.IsEnd())
   {qDebug() << module.GetPosition();
       module.Mix((short*)bytes, frames);
//       for(int i=0; i<1024*4; ++i)
//       {
//           qDebug() << (int)bytes[i];
//       }
   }
 qDebug() << (module.tag->title).c_str();
    qDebug() << (module.tag->composer).c_str();
 qDebug() << (module.tag->author).c_str();
   qDebug() << "end";

    return a.exec();
}
