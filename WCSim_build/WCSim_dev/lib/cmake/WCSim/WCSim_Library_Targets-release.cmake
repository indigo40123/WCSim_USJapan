#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "WCSim::WCSimCore" for configuration "Release"
set_property(TARGET WCSim::WCSimCore APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(WCSim::WCSimCore PROPERTIES
  IMPORTED_LOCATION_RELEASE "/disk02/usr7/licheng/ORNL_SNS/WCSim_Roger/WCSim_build/WCSim_dev/lib/libWCSimCore.so.1.10"
  IMPORTED_SONAME_RELEASE "libWCSimCore.so.1.10"
  )

list(APPEND _IMPORT_CHECK_TARGETS WCSim::WCSimCore )
list(APPEND _IMPORT_CHECK_FILES_FOR_WCSim::WCSimCore "/disk02/usr7/licheng/ORNL_SNS/WCSim_Roger/WCSim_build/WCSim_dev/lib/libWCSimCore.so.1.10" )

# Import target "WCSim::WCSimRoot" for configuration "Release"
set_property(TARGET WCSim::WCSimRoot APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(WCSim::WCSimRoot PROPERTIES
  IMPORTED_LOCATION_RELEASE "/disk02/usr7/licheng/ORNL_SNS/WCSim_Roger/WCSim_build/WCSim_dev/lib/libWCSimRoot.so.1.10"
  IMPORTED_SONAME_RELEASE "libWCSimRoot.so.1.10"
  )

list(APPEND _IMPORT_CHECK_TARGETS WCSim::WCSimRoot )
list(APPEND _IMPORT_CHECK_FILES_FOR_WCSim::WCSimRoot "/disk02/usr7/licheng/ORNL_SNS/WCSim_Roger/WCSim_build/WCSim_dev/lib/libWCSimRoot.so.1.10" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
