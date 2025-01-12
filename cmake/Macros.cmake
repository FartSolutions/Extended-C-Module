macro(ecm_set_option var default type docstring)
    if(NOT DEFINED ${var})
        set(${var} ${default})
    endif()
    set(${var} ${${var}} CACHE ${type} ${docstring} FORCE)
endmacro()

macro(ecm_add_library module)
    cmake_parse_arguments(THIS "STATIC" "DEPENDENCIES" "SOURCES" ${ARGN})
    if(NOT "${THIS_UNPARSED_ARGUMENTS}" STREQUAL "")
        message(FATAL_ERROR "Extra unparsed arguments when calling ecm_add_library: ${THIS_UNPARSED_ARGUMENTS}")
    endif()

    string(TOLOWER ${module} target)
    if(THIS_STATIC)
        add_library(${target} STATIC ${THIS_SOURCES})
    else()
        add_library(${target} ${THIS_SOURCES})
    endif()

    target_compile_features(${target} PUBLIC cxx_std_17)

    if(NOT ECM_OS_ANDROID)
        set_target_properties(${target} PROPERTIES SOVERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH})
        set_target_properties(${target} PROPERTIES VERSION ${PROJECT_VERSION})
    endif()

    set_target_properties(${target} PROPERTIES FOLDER "ECM")

    if(BUILD_SHARED_LIBS)
        set(config_name "Shared")
        target_compile_definitions(${target} PUBLIC "ECM_DYNAMIC_EXPORT")
    else()
        set(config_name "Static")
    endif()

    install(TARGETS ${target} EXPORT ${module}${config_name}Targets
            RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR} COMPONENT bin
            LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR} COMPONENT bin
            ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR} COMPONENT devel
            FRAMEWORK DESTINATION "." COMPONENT bin)

    get_property(ECM_ADD_LIBRARY_MODULES GLOBAL PROPERTY ECM_ADD_LIBRARY_MODULES_PROPERTY)
    list(APPEND ECM_ADD_LIBRARY_MODULES ${module})
    set_property(GLOBAL PROPERTY ECM_ADD_LIBRARY_MODULES_PROPERTY "${ECM_ADD_LIBRARY_MODULES}")

    target_include_directories(${target}
                                PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
                                PRIVATE ${PROJECT_SOURCE_DIR}/src)
endmacro()
