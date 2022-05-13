include($$PWD/../../plugins.pri)

TARGET = $$PLUGINS_PREFIX/Input/mdx

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
           libmdx/mucom88/utils/mucomtag.cpp

INCLUDEPATH += $$PWD/libmdx/fmgen \
               $$PWD/libmdx/mucom88

unix {
    target.path = $$PLUGIN_DIR/Input
    INSTALLS += target
    QMAKE_CLEAN = $$PLUGINS_PREFIX/Input/libmdx.so
}
