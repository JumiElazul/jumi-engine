#ifndef JUMI_ENGINE_CORE_CORE_EXCEPTIONS_H
#define JUMI_ENGINE_CORE_CORE_EXCEPTIONS_H

#include <stdexcept>

namespace jumi
{

    namespace jexcept
    {
        class initialization_exception : public std::exception
        {
        public:
            initialization_exception(const char* message) : _message(message) {}

            inline const char* what() const noexcept override
            {
                return _message;
            }

        private:
            const char* _message;
        };
    }

}

#endif


