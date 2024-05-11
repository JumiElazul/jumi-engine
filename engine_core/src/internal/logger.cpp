#include "engine_core/core/logger.h"
#include <iostream>
#include <magic_enum.hpp>

namespace jumi
{

    void logger::log(log_level level, const char* msg)
    {
        auto enum_name = magic_enum::enum_name(level);
        std::cout << "[JUMI] [" << enum_name << "] " << msg << '\n';
    }

}
