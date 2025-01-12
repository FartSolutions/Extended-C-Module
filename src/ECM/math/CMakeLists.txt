# ecm.math
set(INCROOT ${PROJECT_SOURCE_DIR}/include/ECM/math)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/ECM/math)

# All header files
set(SRC
    ${INCROOT}/../ECM_math.h
    ${INCROOT}/functions.h
    ${INCROOT}/functions_simd.h
    ${INCROOT}/matrix.h
    ${INCROOT}/matrix4x4.h
    ${INCROOT}/vector.h
    ${INCROOT}/vector2.h
    ${INCROOT}/vector3.h
    ${INCROOT}/vector4.h
    ${INCROOT}/ext/vector_ext.h
)
# All source files
list(APPEND SRC
    ${SRCROOT}/functions.cpp
    ${SRCROOT}/functions_simd.cpp
    ${SRCROOT}/matrix4x4.cpp
    ${SRCROOT}/vector2.cpp
    ${SRCROOT}/vector3.cpp
    ${SRCROOT}/vector4.cpp
    ${SRCROOT}/ext/vector_ext.cpp
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
ecm_add_library(ecm.math STATIC
                SOURCES ${SRC} ${PLATFORM_SRC}
                DEPENDENCIES "Dependencies.cmake.in")
