# ecm.graphics
set(INCROOT ${PROJECT_SOURCE_DIR}/include/ECM/opengl)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/ECM/opengl)

# All header files
set(SRC
    ${INCROOT}/../ECM_opengl.h
    ${INCROOT}/glad_gl4.6.h
    ${INCROOT}/glad_khrplatform.h
    ${INCROOT}/glcontext.h
)
# All source files
list(APPEND SRC
    ${SRCROOT}/glad_gl4.6.cpp
    ${SRCROOT}/glcontext.cpp
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
ecm_add_library(ecm.opengl
                SOURCES ${SRC} ${PLATFORM_SRC}
                DEPENDENCIES "Dependencies.cmake.in")

target_link_libraries(ecm.opengl PUBLIC ecm)
target_link_libraries(ecm.opengl PUBLIC ecm.graphics)

target_link_libraries(ecm.opengl PRIVATE SDL2::SDL2)
