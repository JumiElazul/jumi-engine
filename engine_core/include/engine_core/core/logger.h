#ifndef JUMI_ENGINE_ENGINE_CORE_CORE_LOGGER_H
#define JUMI_ENGINE_ENGINE_CORE_CORE_LOGGER_H

#include <string>

#define SPDLOG_LEVEL_NAMES { "TRACE   ", "DEBUG   ", "INFO    ", "WARN    ", "ERROR   ", "CRITICAL", "OFF     " }
#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE
#include <spdlog/spdlog.h>

namespace spdlog
{
    class logger;
}

namespace jumi
{

    enum class log_level
    {
        trace,
        debug,
        info,
        warn,
        error,
        critical,

        none
    };

    class logger
    {
    public:
        static std::shared_ptr<spdlog::logger>& core_logger();

    private:
        static std::shared_ptr<spdlog::logger> s_core_logger;
        static log_level s_log_level;
        static void init();
        static void setup_logger();
        static void print_debug_log_info();
    };

}

#define JUMI_LOGGING_ENABLED
#ifdef JUMI_LOGGING_ENABLED
    #define JUMI_TRACE(...)    SPDLOG_LOGGER_TRACE(jumi::logger::core_logger(), __VA_ARGS__)    
    #define JUMI_DEBUG(...)    SPDLOG_LOGGER_DEBUG(jumi::logger::core_logger(), __VA_ARGS__)    
    #define JUMI_INFO(...)     SPDLOG_LOGGER_INFO(jumi::logger::core_logger(), __VA_ARGS__)    
    #define JUMI_WARN(...)     SPDLOG_LOGGER_WARN(jumi::logger::core_logger(), __VA_ARGS__)    
    #define JUMI_ERROR(...)    SPDLOG_LOGGER_ERROR(jumi::logger::core_logger(), __VA_ARGS__)    
    #define JUMI_CRITICAL(...) SPDLOG_LOGGER_CRITICAL(jumi::logger::core_logger(), __VA_ARGS__)    
#else
    #define JUMI_TRACE(...)
    #define JUMI_DEBUG(...)
    #define JUMI_INFO(...)
    #define JUMI_WARN(...)
    #define JUMI_ERROR(...)
    #define JUMI_CRITICAL(...)
#endif


#endif
