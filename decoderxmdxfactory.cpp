#include "decoderxmdxfactory.h"
#include "xmdxhelper.h"
#include "decoder_xmdx.h"

#include <QMessageBox>

bool DecoderXMDXFactory::canDecode(QIODevice *input) const
{
    const QFile * const file = qobject_cast<QFile*>(input);
    if(!file)
    {
        return false;
    }

    XMDXHelper helper(file->fileName());
    return helper.initialize();
}

DecoderProperties DecoderXMDXFactory::properties() const
{
    DecoderProperties properties;
    properties.name = tr("XMDX Plugin");
    properties.shortName = "xmdx";
    properties.filters << "*.mdx" << "*.pdx";
    properties.filters << "*.m";
    properties.filters << "*.mub" << "*.muc";
    properties.filters << "*.vgs" << "*.bgm" << "*.mml";
    properties.description = "XMDX Game Audio File";
    properties.protocols << "file";
    properties.noInput = true;
    properties.hasAbout = true;
    return properties;
}

Decoder *DecoderXMDXFactory::create(const QString &path, QIODevice *input)
{
    Q_UNUSED(input);
    return new DecoderXMDX(path);
}

QList<TrackInfo*> DecoderXMDXFactory::createPlayList(const QString &path, TrackInfo::Parts parts, QStringList *)
{
    TrackInfo *info = new TrackInfo(path);
    if(parts == TrackInfo::Parts())
    {
        return QList<TrackInfo*>() << info;
    }

    XMDXHelper helper(path);
    if(!helper.initialize())
    {
        delete info;
        return QList<TrackInfo*>();
    }

    if(parts & TrackInfo::MetaData)
    {
        info->setValue(Qmmp::TITLE, helper.title());
        info->setValue(Qmmp::ARTIST, helper.author());
    }

    if(parts & TrackInfo::Properties)
    {
        info->setValue(Qmmp::BITRATE, helper.bitrate());
        info->setValue(Qmmp::SAMPLERATE, helper.sampleRate());
        info->setValue(Qmmp::CHANNELS, helper.channels());
        info->setValue(Qmmp::BITS_PER_SAMPLE, helper.depth());
        info->setValue(Qmmp::FORMAT_NAME, helper.format());
        info->setDuration(helper.totalTime());
    }
    return QList<TrackInfo*>() << info;
}

MetaDataModel* DecoderXMDXFactory::createMetaDataModel(const QString &path, bool readOnly)
{
    Q_UNUSED(path);
    Q_UNUSED(readOnly);
    return nullptr;
}

#if (QMMP_VERSION_INT < 0x10700) || (0x20000 <= QMMP_VERSION_INT && QMMP_VERSION_INT < 0x20200)
void DecoderXMDXFactory::showSettings(QWidget *parent)
{
    Q_UNUSED(parent);
}
#else
QDialog *DecoderXMDXFactory::createSettings(QWidget *parent)
{
    Q_UNUSED(parent);
    return nullptr;
}
#endif

void DecoderXMDXFactory::showAbout(QWidget *parent)
{
    QMessageBox::about(parent, tr("About XMDX Reader Plugin"),
                       tr("Qmmp XMDX Reader Plugin") + "\n" +
                       tr("Written by: Greedysky <greedysky@163.com>") + "\n" +
                       tr("Based on the source code from the mdxmini") + "\n" +
                       tr("Based on the source code from the pmdmini") + "\n" +
                       tr("Based on the source code from the VGS") + "\n" +
                       tr("Based on the source code from the MUCOM88"));
}

QString DecoderXMDXFactory::translation() const
{
    return QString();
}

#if QT_VERSION < QT_VERSION_CHECK(5,0,0)
#include <QtPlugin>
Q_EXPORT_PLUGIN2(xmdx, DecoderXMDXFactory)
#endif
