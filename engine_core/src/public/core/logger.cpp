#include "engine_core/core/logger.h"
#include <memory>
#include <string>

namespace jumi
{

    std::shared_ptr<spdlog::logger> logger::s_core_logger;

    void logger::init()
    {
        static bool s_initialized = false;
        if (!s_initialized)
        {
            setup_logger();
            s_initialized = true;
            print_debug_log_info();
        }
    }

    void logger::setup_logger()
    {
        // Construct color pattern
        std::string pattern;
        pattern = "%^";
        // Show name of the logger
        pattern += "[%n]";
        // Show the log level of the message
        pattern += " [%l]";
        // Show the time of the log message
        pattern += " [%T]";
        // Show the information about the log message, such as time, source file, line number, etc.
        pattern += " [%s, %!, ln %#]";
        // Show log message
        pattern += " %v ";
        // End the color pattern
        pattern += "%$";
        spdlog::set_pattern(pattern);

        s_core_logger = spdlog::stdout_color_mt("JUMI");
        s_core_logger->set_level(spdlog::level::trace);
    }

    std::shared_ptr<spdlog::logger>& logger::core_logger()
    {
        init();
        return s_core_logger;
    }

    void logger::print_debug_log_info()
    {
        JUMI_TRACE("0. Trace logging enabled");
        JUMI_DEBUG("1. Debug logging enabled");
        JUMI_INFO("2. Info logging enabled");
        JUMI_WARN("3. Warn logging enabled");
        JUMI_ERROR("4. Error logging enabled");
        JUMI_CRITICAL("5. Critical logging enabled");
    }

}
