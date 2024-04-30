#ifndef JUMI_ENGINE_CORE_EXCEPTIONS_H
#define JUMI_ENGINE_CORE_EXCEPTIONS_H

#include <stdexcept>

namespace jumi
{

    class initialization_exception : public std::runtime_error
    {
    public:
        initialization_exception(const std::string& message) : std::runtime_error(message) {}
        virtual ~initialization_exception() = default;
    };

}

#endif
