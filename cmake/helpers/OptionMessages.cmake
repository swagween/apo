if (APO_PRODUCTION_BUILD)
    if (APO_DEV_BUILD)
        message(WARNING "APO: APO_PRODUCTION_BUILD is ON, but APO_DEV_BUILD is also ON. Did you mean to do this?")
    endif ()

    if (APO_ENABLE_DEV_ID)
        message(WARNING "APO: APO_PRODUCTION_BUILD is ON, but APO_ENABLE_DEV_ID is also ON. Did you mean to do this?")
    endif ()

    if (APO_ENABLE_PROFILER)
        message(FATAL_ERROR "APO: APO_PRODUCTION_BUILD is ON, but APO_ENABLE_PROFILER is also ON. You should not profile in production!")
    endif ()

    if (APO_ENABLE_VERBOSE_LOGGING)
        message(WARNING "APO: APO_PRODUCTION_BUILD is ON, but APO_ENABLE_VERBOSE_LOGGING is also ON. Did you mean to do this?")
    endif ()
endif ()

if (APO_BUILD_EDITOR)
    message(STATUS "APO: Building editor & launcher!")
else ()
    message(STATUS "APO: Building launcher!")
endif ()

if (APO_DEV_BUILD)
    message(STATUS "APO: APO_DEV_BUILD is ON. Will write steam_appid.txt next to executable!")
endif ()

if (APO_ENABLE_PROFILER)
    message(STATUS "APO: APO_ENABLE_PROFILER is ON. Profiling will now be enabled in the executable!")
endif ()

if (APO_ENABLE_VERBOSE_LOGGING)
    message(STATUS "APO: APO_ENABLE_VERBOSE_LOGGING is ON. Logger will now output verbose logging information!")
endif ()

message(STATUS "APO: Building with steam app ID: ${APO_STEAM_APP_ID}")
