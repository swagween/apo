
cmake_minimum_required(VERSION 3.5...3.29)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if (NOT DEFINED APO_ROOT_DIR)
    set(APO_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR} CACHE STRING "Apo root directory")
endif ()

project(apo
        LANGUAGES CXX
        VERSION 1.0
)

set(APO_STEAM_APP_ID_DEV 480 CACHE STRING "The developer Steam app ID (Spacewar)")

option(APO_PRODUCTION_BUILD "If enabled, will build the game in production mode" OFF)
option(
        APO_DEV_BUILD
        "If enabled, writes a steam_appid.txt file next to the executable
        that will stop the game from relaunching itself through Steam. DISABLE IN PRODUCTION"
        ON
)
option(APO_BUILD_EDITOR "Build the editor. This should never be enabled in production!" ON)
option(APO_ENABLE_DEV_ID "Enables dev ID for steam. This should never be enabled in production!" OFF)
option(
        APO_ENABLE_VERBOSE_LOGGING
        "Enable verbose logging that will output source location information.
        You should only have this enabled if you are debugging!
        This should never be enabled in production!"
        OFF
)

include(cmake/helpers/OptionMessages.cmake)
include(cmake/func/AddTargetSource.cmake)

add_subdirectory(dependencies)
add_subdirectory(game)
add_subdirectory(launcher)

if (APO_DISABLE_DBGHELP)
    target_compile_definitions(${PROJECT_NAME} PRIVATE NANI_DISABLE_ADVANCED_CRASH_REPORTING)
endif ()

if (APO_PRODUCTION_BUILD)
    target_compile_definitions(${PROJECT_NAME} PRIVATE APO_PRODUCTION)
endif ()

