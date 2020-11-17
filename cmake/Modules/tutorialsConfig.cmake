INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(PC_TUTORIALS tutorials)

FIND_PATH(
    TUTORIALS_INCLUDE_DIRS
    NAMES tutorials/api.h
    HINTS $ENV{TUTORIALS_DIR}/include
        ${PC_TUTORIALS_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    TUTORIALS_LIBRARIES
    NAMES gnuradio-tutorials
    HINTS $ENV{TUTORIALS_DIR}/lib
        ${PC_TUTORIALS_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
          )

include("${CMAKE_CURRENT_LIST_DIR}/tutorialsTarget.cmake")

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(TUTORIALS DEFAULT_MSG TUTORIALS_LIBRARIES TUTORIALS_INCLUDE_DIRS)
MARK_AS_ADVANCED(TUTORIALS_LIBRARIES TUTORIALS_INCLUDE_DIRS)
