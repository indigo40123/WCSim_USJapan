#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "WCSim::WCSim" for configuration "Release"
set_property(TARGET WCSim::WCSim APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(WCSim::WCSim PROPERTIES
  IMPORTED_LOCATION_RELEASE "/disk02/usr7/licheng/ORNL_SNS/WCSim_Roger/WCSim_build/WCSim_dev/bin/WCSim"
  )

list(APPEND _IMPORT_CHECK_TARGETS WCSim::WCSim )
list(APPEND _IMPORT_CHECK_FILES_FOR_WCSim::WCSim "/disk02/usr7/licheng/ORNL_SNS/WCSim_Roger/WCSim_build/WCSim_dev/bin/WCSim" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
