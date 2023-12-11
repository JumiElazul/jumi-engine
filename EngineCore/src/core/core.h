#pragma once

#if defined(JUMI_WINDOWS)
    #ifdef JUMI_API_EXPORT
        #define JUMI_API __declspec(dllexport)
    #else
        #define JUMI_API __declspec(dllimport)
    #endif
#else
    #define JUMI_API __attribute__((visibility("default")))
#endif
