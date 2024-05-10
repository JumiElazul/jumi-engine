#ifndef JUMI_ENGINE_ENGINE_CORE_CORE_LOGGER_H
#define JUMI_ENGINE_ENGINE_CORE_CORE_LOGGER_H

#include <memory>

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
        template<typename... Args>
        static void log(log_level level, Args&& args);

    private:
        class logger_impl;
        static std::unique_ptr<logger_impl> s_impl;
    };

}

#define JUMI_LOGGING_ENABLED
#ifdef JUMI_LOGGING_ENABLED
    #define JUMI_TRACE(...)    logger::log(log_level::trace, __VA_ARGS__)
    #define JUMI_DEBUG(...)    logger::log(log_level::debug, __VA_ARGS__)
    #define JUMI_INFO(...)     logger::log(log_level::info, __VA_ARGS__)
    #define JUMI_WARN(...)     logger::log(log_level::warn, __VA_ARGS__)
    #define JUMI_ERROR(...)    logger::log(log_level::error, __VA_ARGS__)
    #define JUMI_CRITICAL(...) logger::log(log_level::critical, __VA_ARGS__)
#else
    #define JUMI_TRACE(...)
    #define JUMI_DEBUG(...)
    #define JUMI_INFO(...)
    #define JUMI_WARN(...)
    #define JUMI_ERROR(...)
    #define JUMI_CRITICAL(...)
#endif


#endif
