#include "decoderxmdxfactory.h"
#include "xmdxhelper.h"
#include "decoder_xmdx.h"

#include <QMessageBox>

bool DecoderXMDXFactory::canDecode(QIODevice *input) const
{
    QFile *file = static_cast<QFile*>(input);
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
    properties.filters << "*.mdx" << "*.pdx" << "*.m" << "*.mub" << "*.muc" << "*.vgs" << "*.bgm" << "*.mml";
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
        info->setValue(Qmmp::FORMAT_NAME, "XMDX");
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

void DecoderXMDXFactory::showSettings(QWidget *parent)
{
    Q_UNUSED(parent);
}

void DecoderXMDXFactory::showAbout(QWidget *parent)
{
    QMessageBox::about(parent, tr("About XMDX Reader Plugin"),
                       tr("Qmmp XMDX Reader Plugin") + "\n" +
                       tr("Written by: Greedysky <greedysky@163.com>"));
}

QString DecoderXMDXFactory::translation() const
{
    return QString();
}
