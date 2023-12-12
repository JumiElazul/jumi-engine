#pragma once

#include <stdexcept>

#ifdef JUMI_WINDOWS
    #ifdef JUMI_API_EXPORT
        #define JUMI_API __declspec(dllexport)
    #else
        #define JUMI_API __declspec(dllimport)
    #endif
#else
    #define JUMI_API __attribute__((visibility("default")))
#endif


#ifdef JUMI_WINDOWS
    #define JUMI_PAUSE __debugbreak()
#else
    #define JUMI_PAUSE assert(false)
#endif

#define JUMI_UNUSED __attribute__((unused))


namespace jumi
{

	class invalid_uniform_location_exception : public std::runtime_error
	{
	public:
		invalid_uniform_location_exception(const char* message) : std::runtime_error(message) { }
	};

	class divide_by_zero_exception : public std::runtime_error
	{
	public:
		divide_by_zero_exception(const char* message) : std::runtime_error(message) { }
	};

	class initialization_exception : public std::runtime_error
	{
	public:
		initialization_exception(const char* message) : std::runtime_error(message) { }
	};

}
