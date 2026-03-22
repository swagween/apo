project(apo-launcher)

if (NOT DEFINED APO_ROOT_DIR)
    message(FATAL_ERROR "APO_ROOT_DIR has not been specified! Did you some how call the launcher cmake only?")
endif ()

add_executable(apo-launcher)
set_target_properties(apo-launcher PROPERTIES OUTPUT_NAME "apo")
target_link_libraries(apo-launcher PRIVATE
        steamworks
        apo::deps
        apo::game
)

target_include_directories(apo-launcher
        PUBLIC include "${CMAKE_CURRENT_BINARY_DIR}/include"
        PRIVATE "src"
)

if ("${CMAKE_CXX_COMPILER_ID}" MATCHES "GNU|Clang|IntelLLVM|AppleClang")
    if ("${CMAKE_CXX_COMPILER_FRONTEND_VARIANT}" STREQUAL "MSVC") # clang-cl
        add_compile_options(apo-launcher INTERFACE /W4056 /W4146 /W4018 /W4056)
    endif ()
    add_compile_options(apo-launcher INTERFACE -Wno-sign-conversion -Wno-format-security)
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    add_compile_options(apo-launcher INTERFACE /W4056 /W4146 /W4018 /W4056)
endif ()

if (APO_ENABLE_DEV_ID AND NOT APO_PRODUCTION_BUILD)
    set(APO_STEAM_APP_ID ${APO_STEAM_APP_ID_DEV} CACHE STRING "Developer Steam App ID: 480")
    target_compile_definitions(${PROJECT_NAME} PUBLIC APO_STEAM_APP_ID=${APO_STEAM_APP_ID_DEV})
else ()
    set(APO_STEAM_APP_ID ${APO_STEAM_APP_ID_DEFAULT} CACHE STRING "Default Steam App ID: 3218760")
    target_compile_definitions(${PROJECT_NAME} PUBLIC APO_STEAM_APP_ID=${APO_STEAM_APP_ID_DEFAULT})
endif ()

add_subdirectory(include/launcher)
add_subdirectory(src)

if (WIN32)
    if (MSVC)
        set(subsystem $<IF:$<BOOL:$<CONFIG:Debug>>,CONSOLE,WINDOWS>)
        target_link_options(apo-launcher PRIVATE
                /SUBSYSTEM:${subsystem}
                /ENTRY:mainCRTStartup
        )
    endif ()
endif ()

copy_steamworks_dll(apo-launcher)

if (APO_DEV_BUILD AND NOT APO_PRODUCTION_BUILD)
    add_custom_command(
            TARGET apo-launcher
            COMMENT "Write steam_appid.txt"
            PRE_LINK COMMAND ${CMAKE_COMMAND} -E echo ${APO_STEAM_APP_ID} > $<TARGET_FILE_DIR:${PROJECT_NAME}>/steam_appid.txt
            VERBATIM
    )
endif ()
