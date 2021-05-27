include(../../plugins.pri)

TARGET = $$PLUGINS_PREFIX/Input/mdx

HEADERS += decodermdxfactory.h \
           decoder_mdx.h \
           mdxhelper.h

SOURCES += decodermdxfactory.cpp \
           decoder_mdx.cpp \
           mdxhelper.cpp \
           libmdx/mdxmini/mdxmini.c \
           libmdx/mdxmini/mdx2151.c \
           libmdx/mdxmini/mdxmml_ym2151.c \
           libmdx/mdxmini/pcm8.c \
           libmdx/mdxmini/mdxfile.c \
           libmdx/mdxmini/ym2151.c \
           libmdx/mdxmini/pdxfile.c \
           libmdx/pmdmini/pmdmini.c \
           libmdx/pmdmini/pmdwin/pmdwin.cpp \
           libmdx/pmdmini/pmdwin/table.cpp \
           libmdx/pmdmini/pmdwin/opnaw.cpp \
           libmdx/pmdmini/pmdwin/p86drv.cpp \
           libmdx/pmdmini/pmdwin/ppsdrv.cpp \
           libmdx/pmdmini/pmdwin/ppz8l.cpp \
           libmdx/pmdmini/pmdwin/util.cpp \
           libmdx/pmdmini/fmgen/fmgen.cpp \
           libmdx/pmdmini/fmgen/opna.cpp \
           libmdx/pmdmini/fmgen/opm.cpp \
           libmdx/pmdmini/fmgen/psg.cpp \
           libmdx/pmdmini/fmgen/file.cpp \
           libmdx/pmdmini/fmgen/fmtimer.cpp

INCLUDEPATH += $$PWD/libmdx/mdxmini \
               $$PWD/libmdx/pmdmini \
               $$PWD/libmdx/pmdmini/fmgen

unix {
    target.path = $$PLUGIN_DIR/Input
    INSTALLS += target
    QMAKE_CLEAN = $$PLUGINS_PREFIX/Input/libmdx.so
}
