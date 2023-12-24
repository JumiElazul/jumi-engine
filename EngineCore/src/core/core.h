#pragma once

#include <cstdint>
#include <memory>
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

    using int8 = std::int8_t;
    using uint8 = std::uint8_t;
    using int16 = std::int16_t;
    using uint16 = std::uint16_t;
    using int32 = std::int32_t;
    using uint32 = std::uint32_t;
    using int64 = std::int64_t;
    using uint64 = std::uint64_t;

	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

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
