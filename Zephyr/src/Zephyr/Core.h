#pragma once

#ifdef ZW_WINDOWS_PLATFORM
	#if ZW_BUILD_DLL
		#define ZW_API __declspec(dllexport)
	#else
		#define ZW_API __declspec(dllimport)
	#endif
#else
	#error Zephyr only supports Windows.
#endif

