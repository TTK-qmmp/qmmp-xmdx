HEADERS += decoderxmdxfactory.h \
           decoder_xmdx.h \
           xmdxhelper.h

SOURCES += decoderxmdxfactory.cpp \
           decoder_xmdx.cpp \
           xmdxhelper.cpp \
           libxmdx/fmgen/fmgen.cpp \
           libxmdx/fmgen/opna.cpp \
           libxmdx/fmgen/opm.cpp \
           libxmdx/fmgen/psg.cpp \
           libxmdx/fmgen/file.cpp \
           libxmdx/fmgen/fmtimer.cpp \
           libxmdx/mdxmini/mdxmini.c \
           libxmdx/mdxmini/mdx2151.c \
           libxmdx/mdxmini/mdxmml_ym2151.c \
           libxmdx/mdxmini/pcm8.c \
           libxmdx/mdxmini/mdxfile.c \
           libxmdx/mdxmini/ym2151.c \
           libxmdx/mdxmini/pdxfile.c \
           libxmdx/pmdmini/pmdmini.cpp \
           libxmdx/pmdmini/pmdwin/pmdwin.cpp \
           libxmdx/pmdmini/pmdwin/table.cpp \
           libxmdx/pmdmini/pmdwin/opnaw.cpp \
           libxmdx/pmdmini/pmdwin/p86drv.cpp \
           libxmdx/pmdmini/pmdwin/ppsdrv.cpp \
           libxmdx/pmdmini/pmdwin/ppz8l.cpp \
           libxmdx/pmdmini/pmdwin/util.cpp \
           libxmdx/mucom88/membuf.cpp \
           libxmdx/mucom88/adpcm.cpp \
           libxmdx/mucom88/md5.c \
           libxmdx/mucom88/cmucom.cpp \
           libxmdx/mucom88/mucomvm.cpp \
           libxmdx/mucom88/Z80/Z80.cpp \
           libxmdx/mucom88/module/mucom_module.cpp \
           libxmdx/mucom88/utils/fade.cpp \
           libxmdx/mucom88/utils/mucomtag.cpp \
           libxmdx/vgs/miniz.c \
           libxmdx/vgs/vgs2tone.c \
           libxmdx/vgs/vgsdec.c \
           libxmdx/vgs/vgsmml.c

INCLUDEPATH += $$PWD/libxmdx/fmgen \
               $$PWD/libxmdx/mucom88

#CONFIG += BUILD_PLUGIN_INSIDE
contains(CONFIG, BUILD_PLUGIN_INSIDE){
    include($$PWD/../../plugins.pri)
    TARGET = $$PLUGINS_PREFIX/Input/xmdx

    unix{
        target.path = $$PLUGIN_DIR/Input
        INSTALLS += target
    }

    win32{
        LIBS += -lws2_32
    }
}else{
    CONFIG += warn_off plugin lib thread link_pkgconfig c++11
    TEMPLATE = lib

    unix{
        equals(QT_MAJOR_VERSION, 5){
            QMMP_PKG = qmmp-1
        }else:equals(QT_MAJOR_VERSION, 6){
            QMMP_PKG = qmmp
        }else{
            error("Unsupported Qt version: 5 or 6 is required")
        }
        
        PKGCONFIG += $${QMMP_PKG}

        PLUGIN_DIR = $$system(pkg-config $${QMMP_PKG} --variable=plugindir)/Input
        INCLUDEPATH += $$system(pkg-config $${QMMP_PKG} --variable=prefix)/include

        plugin.path = $${PLUGIN_DIR}
        plugin.files = lib$${TARGET}.so
        INSTALLS += plugin
    }
}
