#include "engine_core/core/logger.h"
#include <memory>

namespace jumi
{

    std::shared_ptr<spdlog::logger> logger::s_core_logger;
    bool logger::s_initialized = false;

    void logger::init()
    {
        spdlog::set_pattern("%^[%T, %s, %!, line: %#] [%n] %v%$");
        s_core_logger = spdlog::stdout_color_mt("JUMI");
        s_core_logger->set_level(spdlog::level::trace);

        s_initialized = true;
    }

    std::shared_ptr<spdlog::logger>& logger::core_logger()
    {
        return s_core_logger;
    }

    void logger::print_debug_log_info()
    {
        if (!s_initialized)
        {
            throw initialization_exception("Logger not initialized");
        }

        JUMI_TRACE("0. Trace logging enabled");
        JUMI_DEBUG("1. Debug logging enabled");
        JUMI_INFO("2. Info logging enabled");
        JUMI_WARN("3. Warn logging enabled");
        JUMI_ERROR("4. Error logging enabled");
        JUMI_CRITICAL("5. Critical logging enabled");
    }
}
