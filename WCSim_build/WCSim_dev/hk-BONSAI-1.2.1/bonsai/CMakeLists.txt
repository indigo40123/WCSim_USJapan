include_directories(BEFORE
        ${CMAKE_CURRENT_SOURCE_DIR}
        )

#file(GLOB_RECURSE SRC RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "*.cc")
#file(GLOB_RECURSE HEADERS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "*.h")

set(HEADERS
        binfile.h
        bonsai.h
        bonsaifit.h
        bonsaifit.inl
        bscalls.h
        centroid.h
        centroid.inl
        fit_param.h
        fitquality.h
        fourhitgrid.h
        goodness.h
        goodness.inl
        hits.h
        hits.inl
        hitsel.h
        hitsel.inl
        likelihood.h
        likelihood.inl
        plato.h
        pmt_geometry.h
        pot.h
        searchgrid.h
        timefit.h
        timefit.inl
        tree.h
        vertex.h
        vertex.inl
        vertexfit.h
        WCSimBonsai.hh)

set (SRC
        fit_param.cc
        pmt_geometry.cc
        binfile.cc
        bonsai.cc
        bonsaifit.cc
        plato.cc
        searchgrid.cc
        fourhitgrid.cc
        centroid.cc
        hits.cc
        hitsel.cc
        goodness.cc
        timefit.cc
        likelihood.cc
        vertex.cc
        pot.cc
        tree.cc
        vertexfit.cc
        bscalls.cc
        )

# Prepare root dictionary
set(dict_headers
        WCSimBonsai.hh
        )
# add dictionary to source files
set(SRC ${SRC} ${CMAKE_CURRENT_BINARY_DIR}/G__BONSAI.cxx)

set(BONSAI_LINKDEF_HEADERFILE WCSimBonsaiLinkDef.hh)
set(BONSAI_DICT_PCMFILE ${CMAKE_CURRENT_BINARY_DIR}/libBONSAI_rdict.pcm)
set(BONSAI_DICT_ROOTMAPFILE ${CMAKE_CURRENT_BINARY_DIR}/libBONSAI.rootmap)


ROOT_GENERATE_DICTIONARY(G__BONSAI ${dict_headers} LINKDEF ${BONSAI_LINKDEF_HEADERFILE})
pbuilder_install_files(${LIB_INSTALL_DIR} ${BONSAI_DICT_PCMFILE} ${BONSAI_DICT_ROOTMAPFILE})


# Prepare bonsai library
pbuilder_library(
        TARGET bonsai
        SOURCES ${SRC}
#        PROJECT_LIBRARIES hk-ToolFrameworkCore::ToolFrameworkCore
        PUBLIC_EXTERNAL_LIBRARIES ${PUBLIC_EXT_LIBS}
        PRIVATE_EXTERNAL_LIBRARIES ${PRIVATE_EXT_LIBS}
)
#
pbuilder_install_headers(${HEADERS})


pbuilder_component_install_and_export(
        COMPONENT Library
        LIBTARGETS bonsai
)