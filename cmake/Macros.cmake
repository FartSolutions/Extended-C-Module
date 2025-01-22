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
    string(TOUPPER ${module} target_upper)
    string(REPLACE "." "_" target_upper "${target_upper}")

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

    if(BUILD_SHARED_LIBS AND NOT THIS_STATIC)
        set(config_name "Shared")
        target_compile_definitions(${target} PUBLIC "${target_upper}_DYNAMIC")
        target_compile_definitions(${target} PRIVATE "${target_upper}_DYNAMIC_EXPORT")

        if(ECM_OS_WINDOWS)
            string(TIMESTAMP RC_CURRENT_YEAR "%Y")
            #string(REGEX REPLACE "ecm.([a-z])([a-z]*)" "\\1" RC_MODULE_NAME_HEAD "${target}")
            #string(REGEX REPLACE "ecm.([a-z])([a-z]*)" "\\2" RC_MODULE_NAME_TAIL "${target}")
            #string(TOUPPER "${RC_MODULE_NAME_HEAD}" RC_MODULE_NAME_HEAD)
            #set(RC_MODULE_NAME "${RC_MODULE_NAME_HEAD}${RC_MODULE_NAME_TAIL}")
            string(REPLACE "_" " " RC_MODULE_NAME "${target_upper}")
            set(RC_VERSION_SUFFIX "")
            set(RC_PRERELEASE "0")
            set(RC_TARGET_NAME "${target}")
            set(RC_TARGET_FILE_NAME_SUFFIX "${CMAKE_SHARED_LIBRARY_SUFFIX}")

            configure_file(
                "${PROJECT_SOURCE_DIR}/rsc/windows/resource.rc.in"
                "${CMAKE_CURRENT_BINARY_DIR}/${target}.rc"
                @ONLY
            )
            target_sources(${target} PRIVATE "${CMAKE_CURRENT_BINARY_DIR}/${target}.rc")
            source_group("" FILES "${CMAKE_CURRENT_BINARY_DIR}/${target}.rc")
        else()
            set_target_properties(${target} PROPERTIES DEBUG_POSTFIX -d)
        endif()
    else()
        set(config_name "Static")

        set_target_properties(${target} PROPERTIES DEBUG_POSTFIX -d)
        #set_target_properties(${target} PROPERTIES RELEASE_POSTFIX -s)
        #set_target_properties(${target} PROPERTIES MINSIZEREL_POSTFIX -s)
        #set_target_properties(${target} PROPERTIES RELWITHDEBINFO_POSTFIX -s)
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

    target_include_directories(${target}
                                SYSTEM PRIVATE "${PROJECT_SOURCE_DIR}/vendor")
endmacro()
