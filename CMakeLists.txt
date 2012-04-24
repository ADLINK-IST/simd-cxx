#
# CMake configuration file for SimD
#
cmake_minimum_required (VERSION 2.6)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
project (simd-cxx)
# project version
SET( ${PROJECT_NAME}_MAJOR_VERSION 1)
SET( ${PROJECT_NAME}_MINOR_VERSION 0)
SET( ${PROJECT_NAME}_PATCH_LEVEL 0)
SET( ${PROJECT_NAME}_VERSION 1.0.0)
SET( ${PROJECT_NAME}_SOVERSION 1.0.0)

# project options
OPTION( BUILD_SHARED_LIBS "Set to OFF to build static libraries" ON )
#OPTION( INSTALL_DOC "Set to OFF to skip build/install Documentation" ON )


# set default install prefix to project root directory
IF( CMAKE_INSTALL_PREFIX STREQUAL "/usr/local" )
    SET( CMAKE_INSTALL_PREFIX "${PROJECT_SOURCE_DIR}/local" )
ENDIF()

# find_package (Doxygen)

# if (DOXYGEN_FOUND)
#   message(STATUS "Generating SimD Documentation")
#   exec_program("${DOXYGEN_EXECUTABLE} doxygen.cfg")
# else (DOXYGEN_FOUND)
#   message(STATUS "Doxygen not found, I cannot generate the documentation")
# endif (DOXYGEN_FOUND)

add_subdirectory (src)

