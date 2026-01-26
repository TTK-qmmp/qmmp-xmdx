cmake_minimum_required(VERSION 3.0)

project(xmdx)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/fmgen)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/mucom88)

set(MDX_HEADERS
    mdxmini/mdx.h
    mdxmini/pcm8.h
    mdxmini/mdxmini.h
)

set(MDX_SOURCES
    mdxmini/mdxmini.c
    mdxmini/mdx2151.c
    mdxmini/mdxmml_ym2151.c
    mdxmini/pcm8.c
    mdxmini/mdxfile.c
    mdxmini/ym2151.c
    mdxmini/pdxfile.c
)

set(PMD_HEADERS
    pmdmini/pmdmini.h
)

set(PMD_SOURCES
    pmdmini/pmdmini.cpp
    pmdmini/pmdwin/pmdwin.cpp
    pmdmini/pmdwin/table.cpp
    pmdmini/pmdwin/opnaw.cpp
    pmdmini/pmdwin/p86drv.cpp
    pmdmini/pmdwin/ppsdrv.cpp
    pmdmini/pmdwin/ppz8l.cpp
    pmdmini/pmdwin/util.cpp
)

set(MUCOM_SOURCES
    mucom88/membuf.cpp
    mucom88/adpcm.cpp
    mucom88/md5.c
    mucom88/cmucom.cpp
    mucom88/mucomvm.cpp
    mucom88/Z80/Z80.cpp
    mucom88/module/mucom_module.cpp
    mucom88/utils/fade.cpp
    mucom88/utils/mucomtag.cpp
)

set(VGS_HEADERS
    vgs/vgsdec.h 
    vgs/vgsmml.h
)

set(VGS_SOURCES
    vgs/miniz.c
    vgs/vgs2tone.c
    vgs/vgsdec.c
    vgs/vgsmml.c
)

set(SOURCES
    fmgen/fmgen.cpp
    fmgen/opna.cpp
    fmgen/opm.cpp
    fmgen/psg.cpp
    fmgen/file.cpp
    fmgen/fmtimer.cpp
    ${MDX_SOURCES}
    ${PMD_SOURCES}
    ${MUCOM_SOURCES}
    ${VGS_SOURCES}
)

add_library(${PROJECT_NAME} STATIC ${SOURCES} ${MDX_HEADERS} ${PMD_HEADERS} ${VGS_HEADERS})
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME ${PROJECT_NAME}${STATIC_LIB_SUFFIX})

install(TARGETS ${PROJECT_NAME}
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    COMPONENT library
)

install(FILES ${MDX_HEADERS} DESTINATION ${CMAKE_INSTALL_PREFIX}/include/lib${PROJECT_NAME}/mdxmini)
install(FILES ${PMD_HEADERS} DESTINATION ${CMAKE_INSTALL_PREFIX}/include/lib${PROJECT_NAME}/pmdmini)
install(FILES mucom88/module/mucom_module.h DESTINATION ${CMAKE_INSTALL_PREFIX}/include/lib${PROJECT_NAME}/mucom88/module)
install(FILES mucom88/utils/mucomtag.h DESTINATION ${CMAKE_INSTALL_PREFIX}/include/lib${PROJECT_NAME}/mucom88/utils)
install(FILES ${VGS_HEADERS} DESTINATION ${CMAKE_INSTALL_PREFIX}/include/lib${PROJECT_NAME}/vgs)
