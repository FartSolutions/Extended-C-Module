include(${PROJECT_SOURCE_DIR}/cmake/Macros.cmake)

include(FetchContent)
FetchContent_Declare(
    SDL2
    GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
    GIT_TAG release-2.30.0
)
FetchContent_MakeAvailable(SDL2)

# Maybe in future
# list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/Modules")

set(LIBRARY_OUTPUT_PATH "${PROJECT_BINARY_DIR}/lib")

# ecm.core
set(INCROOT ${PROJECT_SOURCE_DIR}/include/ECM)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/ECM)

# All header files
set(SRC
    ${INCROOT}/ECM.h
    ${INCROOT}/ECM_api.h
    ${INCROOT}/ECM_configs.h
    ${INCROOT}/ECM_stdinc.h
    ${INCROOT}/ECM_stdtypes.h
    ${INCROOT}/ECM_version.h
    ${INCROOT}/ECM_console.h
    ${INCROOT}/ECM_color.h
)
# All source files
list(APPEND SRC
    ${SRCROOT}/version.cpp
    ${SRCROOT}/console.cpp
    ${SRCROOT}/color.cpp
)
source_group("" FILES ${SRC})

# Add platform specific sources
if(ECM_OS_WINDOWS)
    set(PLATFORM_SRC )
    source_group("windows" FILES ${PLATFORM_SRC})
else()
    set(PLATFORM_SRC)
    if(ECM_OS_ANDROID)
        list(APPEND PLATFORM_SRC )
    endif()
    source_group("unix" FILES ${PLATFORM_SRC})
endif()

# Project ecm
ecm_add_library(ecm
                SOURCES ${SRC} ${PLATFORM_SRC}
                DEPENDENCIES "Dependencies.cmake.in")

# ecm.math
if(ECM_BUILD_MATH)
    add_subdirectory(math)
endif()

# ecm.Graphics
if(ECM_BUILD_GRAPHICS)
    add_subdirectory(graphics)
endif()

# ecm.opengl
if(ECM_BUILD_OPENGL)
    add_subdirectory(opengl)
endif()
