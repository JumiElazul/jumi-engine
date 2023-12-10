#pragma once

#ifdef JUMIAPI_EXPORT
    #define JUMI_API __attribute__((visibility("default")))
#else
    #define JUMI_API
#endif

namespace jumi
{

    int JUMI_API add(int a, int b);

}

