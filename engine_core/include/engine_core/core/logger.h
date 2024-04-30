#ifndef JUMI_ENGINE_CORE_LOGGER_H
#define JUMI_ENGINE_CORE_LOGGER_H

#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE
#include "engine_core/core/exceptions.h"
#include <spdlog/spdlog.h>
#include "spdlog/sinks/stdout_color_sinks.h"
#include <memory>

#define JUMI_LOGGING_ENABLED
    #define JUMI_TRACE(...)    SPDLOG_LOGGER_TRACE(jumi::logger::core_logger(), __VA_ARGS__)
    #define JUMI_DEBUG(...)    SPDLOG_LOGGER_DEBUG(jumi::logger::core_logger(), __VA_ARGS__)
    #define JUMI_INFO(...)     SPDLOG_LOGGER_INFO(jumi::logger::core_logger(), __VA_ARGS__)
    #define JUMI_WARN(...)     SPDLOG_LOGGER_WARN(jumi::logger::core_logger(), __VA_ARGS__)
    #define JUMI_ERROR(...)    SPDLOG_LOGGER_ERROR(jumi::logger::core_logger(), __VA_ARGS__)
    #define JUMI_CRITICAL(...) SPDLOG_LOGGER_CRITICAL(jumi::logger::core_logger(), __VA_ARGS__)
#ifndef JUMI_LOGGING_ENABLED
    #define JUMI_TRACE(...)
    #define JUMI_DEBUG(...)
    #define JUMI_INFO(...)
    #define JUMI_WARN(...)
    #define JUMI_ERROR(...)
    #define JUMI_CRITICAL(...)
#endif

namespace jumi
{

    class logger
    {
    public:
        static void init();
        static std::shared_ptr<spdlog::logger>& core_logger();
        static void print_debug_log_info();

    private:
        static std::shared_ptr<spdlog::logger> s_core_logger;
        static bool s_initialized;
    };

}

#endif
