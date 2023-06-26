# Install script for directory: /disk02/usr7/licheng/ORNL_SNS/WCSim_Roger

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/disk02/usr7/licheng/ORNL_SNS/WCSim_Roger/WCSim_build/WCSim_dev")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "0")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/disk02/usr7/licheng/ORNL_SNS/WCSim_Roger/WCSim_build/WCSim_dev/data/MuonFlux-HyperK-ThetaPhi.dat")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/disk02/usr7/licheng/ORNL_SNS/WCSim_Roger/WCSim_build/WCSim_dev/data" TYPE FILE FILES "/disk02/usr7/licheng/ORNL_SNS/WCSim_Roger/data/MuonFlux-HyperK-ThetaPhi.dat")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/disk02/usr7/licheng/ORNL_SNS/WCSim_Roger/WCSim_build/WCSim_dev/macros/jobOptions.mac;/disk02/usr7/licheng/ORNL_SNS/WCSim_Roger/WCSim_build/WCSim_dev/macros/daq.mac;/disk02/usr7/licheng/ORNL_SNS/WCSim_Roger/WCSim_build/WCSim_dev/macros/visOGLSX.mac;/disk02/usr7/licheng/ORNL_SNS/WCSim_Roger/WCSim_build/WCSim_dev/macros/visRayTracer.mac;/disk02/usr7/licheng/ORNL_SNS/WCSim_Roger/WCSim_build/WCSim_dev/macros/visOGLQT.mac;/disk02/usr7/licheng/ORNL_SNS/WCSim_Roger/WCSim_build/WCSim_dev/macros/visOGLQT_2.mac;/disk02/usr7/licheng/ORNL_SNS/WCSim_Roger/WCSim_build/WCSim_dev/macros/tuning_parameters.mac;/disk02/usr7/licheng/ORNL_SNS/WCSim_Roger/WCSim_build/WCSim_dev/macros/OD.mac;/disk02/usr7/licheng/ORNL_SNS/WCSim_Roger/WCSim_build/WCSim_dev/macros/OD_10k.mac")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/disk02/usr7/licheng/ORNL_SNS/WCSim_Roger/WCSim_build/WCSim_dev/macros" TYPE FILE FILES
    "/disk02/usr7/licheng/ORNL_SNS/WCSim_Roger/macros/jobOptions.mac"
    "/disk02/usr7/licheng/ORNL_SNS/WCSim_Roger/macros/daq.mac"
    "/disk02/usr7/licheng/ORNL_SNS/WCSim_Roger/macros/visOGLSX.mac"
    "/disk02/usr7/licheng/ORNL_SNS/WCSim_Roger/macros/visRayTracer.mac"
    "/disk02/usr7/licheng/ORNL_SNS/WCSim_Roger/macros/visOGLQT.mac"
    "/disk02/usr7/licheng/ORNL_SNS/WCSim_Roger/macros/visOGLQT_2.mac"
    "/disk02/usr7/licheng/ORNL_SNS/WCSim_Roger/macros/tuning_parameters.mac"
    "/disk02/usr7/licheng/ORNL_SNS/WCSim_Roger/macros/OD.mac"
    "/disk02/usr7/licheng/ORNL_SNS/WCSim_Roger/macros/OD_10k.mac"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/disk02/usr7/licheng/ORNL_SNS/WCSim_Roger/WCSim_build/WCSim_dev/WCSim.mac")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/disk02/usr7/licheng/ORNL_SNS/WCSim_Roger/WCSim_build/WCSim_dev" TYPE FILE FILES "/disk02/usr7/licheng/ORNL_SNS/WCSim_Roger/WCSim.mac")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/disk02/usr7/licheng/ORNL_SNS/WCSim_Roger/WCSim_build/WCSim_dev/bin/rootwc/loadincs.C;/disk02/usr7/licheng/ORNL_SNS/WCSim_Roger/WCSim_build/WCSim_dev/bin/rootwc/loadlibs.C;/disk02/usr7/licheng/ORNL_SNS/WCSim_Roger/WCSim_build/WCSim_dev/bin/rootwc/rootwc;/disk02/usr7/licheng/ORNL_SNS/WCSim_Roger/WCSim_build/WCSim_dev/bin/rootwc/rootwc.C")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/disk02/usr7/licheng/ORNL_SNS/WCSim_Roger/WCSim_build/WCSim_dev/bin/rootwc" TYPE FILE FILES
    "/disk02/usr7/licheng/ORNL_SNS/WCSim_Roger/rootwc/loadincs.C"
    "/disk02/usr7/licheng/ORNL_SNS/WCSim_Roger/rootwc/loadlibs.C"
    "/disk02/usr7/licheng/ORNL_SNS/WCSim_Roger/rootwc/rootwc"
    "/disk02/usr7/licheng/ORNL_SNS/WCSim_Roger/rootwc/rootwc.C"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/disk02/usr7/licheng/ORNL_SNS/WCSim_Roger/WCSim_build/WCSim_dev/lib/cmake/WCSim/WCSimConfigVersion.cmake;/disk02/usr7/licheng/ORNL_SNS/WCSim_Roger/WCSim_build/WCSim_dev/lib/cmake/WCSim/WCSimConfig.cmake")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/disk02/usr7/licheng/ORNL_SNS/WCSim_Roger/WCSim_build/WCSim_dev/lib/cmake/WCSim" TYPE FILE FILES
    "/disk02/usr7/licheng/ORNL_SNS/WCSim_Roger/WCSim_build/WCSim_dev/WCSimConfigVersion.cmake"
    "/disk02/usr7/licheng/ORNL_SNS/WCSim_Roger/WCSim_build/WCSim_dev/WCSimConfig.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/disk02/usr7/licheng/ORNL_SNS/WCSim_Roger/WCSim_build/WCSim_dev/bin/this_wcsim.sh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/disk02/usr7/licheng/ORNL_SNS/WCSim_Roger/WCSim_build/WCSim_dev/bin" TYPE FILE FILES "/disk02/usr7/licheng/ORNL_SNS/WCSim_Roger/WCSim_build/WCSim_dev/this_wcsim.sh")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/disk02/usr7/licheng/ORNL_SNS/WCSim_Roger/WCSim_build/WCSim_dev/src/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/disk02/usr7/licheng/ORNL_SNS/WCSim_Roger/WCSim_build/WCSim_dev/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
