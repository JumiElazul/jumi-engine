#include "engine_core/core/logger.h"
#include <magic_enum.hpp>
#include <fmt/format.h>
#include <string>

namespace jumi
{

    void logger::log(log_level level, const char* msg)
    {
        auto enum_name = magic_enum::enum_name(level);
        fmt::print("[JUMI] [{}] {}\n", enum_name, msg);
    }

    void logger::log(log_level level, const std::string& msg)
    {
        auto enum_name = magic_enum::enum_name(level);
        fmt::print("[JUMI] [{}] {}\n", enum_name, msg);
    }

}
