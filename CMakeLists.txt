######################################################################################
### 1) Set your application properties
######################################################################################
# check cmake version compatibility
cmake_minimum_required(VERSION 3.5) 

# Here define your project name
project(TTP)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11") # enable C++11 standard

# Here define the name and the version of your package
set(PACKAGE_NAME "packageName" CACHE STRING "Package name" FORCE)
set(PACKAGE_VERSION "versionNumber" CACHE STRING "Package version" FORCE)

# set a language for the entire project.
enable_language(CXX)
enable_language(C)

# find a OpenMP library to use in eoParallel.
find_package(OpenMP)

if(OPENMP_FOUND)
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
endif()

#SET(PARADISEO_ROOT "C:\\ParadisEO")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/module")

find_package(Paradiseo)

include_directories(${PARADISEO_INCLUDE_DIR})

link_directories(${PARADISEO_ROOT}/build/eo/lib/)

######################################################################################

######################################################################################
### 2) include the sources
######################################################################################

# include required modules & utilities
include(CMakeBackwardCompatibilityCXX)

include(FindDoxygen)

include(FindGnuplot)

include(CheckLibraryExists)

# Manage the build type
# the user should choose the build type on windows environments,excepted under cygwin (default=none)
set(CMAKE_DEFAULT_BUILD_TYPE "none" CACHE STRING "Variable that stores the default CMake build type" FORCE)

if(CMAKE_BUILD_TYPE MATCHES Debug)
    add_definitions(-DCMAKE_VERBOSE_MAKEFILE=ON)
endif(CMAKE_BUILD_TYPE MATCHES Debug)

add_definitions(-DDEPRECATED_MESSAGES)

file(COPY "instances" DESTINATION "${CMAKE_BINARY_DIR}")

######################################################################################
### 3) Link the librairies for your executable
######################################################################################

add_subdirectory(src)
add_subdirectory(application)

######################################################################################
