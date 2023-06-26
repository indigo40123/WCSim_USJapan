# Minimum cmake verison 3.1 required for the variable CMAKE_CXX_STANDARD
cmake_minimum_required(VERSION 3.1)


set(PROJECT_NAME hk-BONSAI)

list(APPEND CMAKE_MODULE_PATH
        $ENV{HK_PILOT_DIR}/cmake
        )
include(GetVersionGit)
MESSAGE("Preparing project ${PROJECT_NAME} version ${PROJECT_VERSION}" )
project(${PROJECT_NAME} VERSION 1.2.0)
include(HKPackageBuilder)
hkbuilder_prepare_project()
set( PUBLIC_EXT_LIBS )
hk_check_dependencies()

MESSAGE (STATUS "PUBLIC_EXT_LIBS: ${PUBLIC_EXT_LIBS}")

add_subdirectory(bonsai)