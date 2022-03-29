#pragma once

#include<string>

#ifdef ZW_WINDOWS_PLATFORM
	#if ZW_BUILD_DLL
		#define ZEPHYR_API __declspec(dllexport)
	#else
		#define ZEPHYR_API __declspec(dllimport)
	#endif
#else
	#error Zephyr only supports Windows.
#endif

#ifdef ZW_ENABLE_ASSERTS
#define ZW_ASSERT(x, ...) { if(!(x)) { HZ_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#define ZW_ENGINE_ASSERT(x, ...) { if(!(x)) { HZ_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
#define ZW_ASSERT(x, ...)
#define ZW_ENGINE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)