# ecm.graphics
set(INCROOT ${PROJECT_SOURCE_DIR}/include/ECM/graphics)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/ECM/graphics)

# All header files
set(SRC
    ${INCROOT}/../ECM_graphics.h
    ${INCROOT}/context.h
    ${INCROOT}/events.h
    ${INCROOT}/sdlrenderer.h
    ${INCROOT}/window.h
)
# All source files
list(APPEND SRC
    ${SRCROOT}/context.cpp
    ${SRCROOT}/sdlrenderer.cpp
    ${SRCROOT}/window.cpp
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
ecm_add_library(ecm.graphics
                SOURCES ${SRC} ${PLATFORM_SRC}
                DEPENDENCIES "Dependencies.cmake.in")
