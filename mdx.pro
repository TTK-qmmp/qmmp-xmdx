HEADERS += decodermdxfactory.h \
           decoder_mdx.h \
           mdxhelper.h

SOURCES += decodermdxfactory.cpp \
           decoder_mdx.cpp \
           mdxhelper.cpp \
           libmdx/fmgen/fmgen.cpp \
           libmdx/fmgen/opna.cpp \
           libmdx/fmgen/opm.cpp \
           libmdx/fmgen/psg.cpp \
           libmdx/fmgen/file.cpp \
           libmdx/fmgen/fmtimer.cpp \
           libmdx/mdxmini/mdxmini.c \
           libmdx/mdxmini/mdx2151.c \
           libmdx/mdxmini/mdxmml_ym2151.c \
           libmdx/mdxmini/pcm8.c \
           libmdx/mdxmini/mdxfile.c \
           libmdx/mdxmini/ym2151.c \
           libmdx/mdxmini/pdxfile.c \
           libmdx/pmdmini/pmdmini.cpp \
           libmdx/pmdmini/pmdwin/pmdwin.cpp \
           libmdx/pmdmini/pmdwin/table.cpp \
           libmdx/pmdmini/pmdwin/opnaw.cpp \
           libmdx/pmdmini/pmdwin/p86drv.cpp \
           libmdx/pmdmini/pmdwin/ppsdrv.cpp \
           libmdx/pmdmini/pmdwin/ppz8l.cpp \
           libmdx/pmdmini/pmdwin/util.cpp \
           libmdx/mucom88/membuf.cpp \
           libmdx/mucom88/adpcm.cpp \
           libmdx/mucom88/md5.c \
           libmdx/mucom88/cmucom.cpp \
           libmdx/mucom88/mucomvm.cpp \
           libmdx/mucom88/Z80/Z80.cpp \
           libmdx/mucom88/module/mucom_module.cpp \
           libmdx/mucom88/utils/fade.cpp \
           libmdx/mucom88/utils/mucomtag.cpp \
           libmdx/vgs/miniz.c \
           libmdx/vgs/vgs2tone.c \
           libmdx/vgs/vgsdec.c \
           libmdx/vgs/vgsmml.c

INCLUDEPATH += $$PWD/libmdx/fmgen \
               $$PWD/libmdx/mucom88

#CONFIG += BUILD_PLUGIN_INSIDE
contains(CONFIG, BUILD_PLUGIN_INSIDE){
    include($$PWD/../../plugins.pri)
    TARGET = $$PLUGINS_PREFIX/Input/mdx

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
        PKGCONFIG += qmmp-1

        PLUGIN_DIR = $$system(pkg-config qmmp-1 --variable=plugindir)/Input
        INCLUDEPATH += $$system(pkg-config qmmp-1 --variable=prefix)/include

        plugin.path = $${PLUGIN_DIR}
        plugin.files = lib$${TARGET}.so
        INSTALLS += plugin
    }
}
