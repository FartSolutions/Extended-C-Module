cmake_minimum_required(VERSION 3.22)

# Include the macros
include(cmake/Macros.cmake)

# This library based on C++ 17 functionalities
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

ecm_set_option(CMAKE_BUILD_TYPE Release STRING "Choose Debug or Release as build type")
ecm_set_option(BUILD_SHARED_LIBS ON BOOL "ON to build ECM's modules as shared libraries")

# Set the project
project(ExtendedCModule LANGUAGES CXX VERSION 1.0.0)

# Include the config
include(cmake/Config.cmake)

# Disable static libraries on Android
if(ECM_OS_ANDROID)
    set(BUILD_SHARED_LIBS ON)
endif()

# Build libraries options
ecm_set_option(ECM_BUILD_MATH ON BOOL "ON to build ECM's Math module. This setting is ignored, if dependent modules require it")
ecm_set_option(ECM_BUILD_GRAPHICS ON BOOL "ON to build ECM's Graphics module. This setting is ignored, if dependent modules require it")
ecm_set_option(ECM_BUILD_OPENGL ON BOOL "ON to build ECM's OpenGL module")

# Force building ecm.math
set(ECM_BUILD_MATH ON)

# Force building ecm.Graphics
if(ECM_BUILD_OPENGL AND NOT ECM_BUILD_GRAPHICS)
    message(WARNING "Force building of the Graphics module, as another one is dependent on it")
    set(ECM_BUILD_GRAPHICS ON)
endif()

# Define an option for choosing between static and dynamic runtime
if(ECM_OS_WINDOWS)
    ecm_set_option(ECM_USE_STATIC_STDLIBS OFF BOOL "ON to statically link to the standard libraries, OFF to use them as DLLs")
    if(BUILD_SHARED_LIBS AND ECM_USE_STATIC_STDLIBS)
        message(FATAL_ERROR "BUILD_SHARED_LIBS and ECM_USE_STATIC_STD_LIBS cannot be used together")
    endif()
endif()

option(ECM_ENABLE_STDLIB_ASSERTIONS "Enable standard library assertions" OFF)
if (ECM_ENABLE_STDLIB_ASSERTIONS)
    add_definitions(-D_GLIBCXX_ASSERTIONS=1)
    add_definitions(-D_LIBCPP_HARDENING_MODE=_LIBCPP_HARDENING_MODE_EXTENSIVE)
endif()

# Set the output directory for ECM shared libraries and executables
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

# Enable project folders
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "CMake")

# Add the project subdirectories
add_subdirectory(src/ECM)
