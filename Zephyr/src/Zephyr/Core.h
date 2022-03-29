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

#define BIT(x) (1 << x)