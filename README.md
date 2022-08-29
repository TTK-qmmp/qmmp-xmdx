This is a plugin for Qmmp (1.6.0 or greater) which supports XMDX file.
(MDXMINI and PMDMINI and PDXMINI and VGS and MUCOM88 Audio File)

The following packages are required, including development headers,
which some vendors split into separate packages:

- qmmp
- qt5

To build, run Qt5's qmake (often installed as qmake-qt5) and then build
with make:

$ qmake-qt5

$ make

To install:

$ make install

This installs the plugin into Qmmp's input plugin directory.  To install
to a staging area, such as for packaging:

$ make install INSTALL_ROOT=/path/to/staging
