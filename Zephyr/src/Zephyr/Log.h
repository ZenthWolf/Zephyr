#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Zephyr
{
	class ZEPHYR_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetEngineLogger() { return engineLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return clientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> engineLogger;
		static std::shared_ptr<spdlog::logger> clientLogger;
	};
}

//Engine Log Macros
#define ZW_ENGINE_TRACE(...) ::Zephyr::Log::GetEngineLogger()->trace(__VA_ARGS__)
#define ZW_ENGINE_INFO(...)  ::Zephyr::Log::GetEngineLogger()->info(__VA_ARGS__)
#define ZW_ENGINE_WARN(...)  ::Zephyr::Log::GetEngineLogger()->warn(__VA_ARGS__)
#define ZW_ENGINE_ERROR(...) ::Zephyr::Log::GetEngineLogger()->error(__VA_ARGS__)
#define ZW_ENGINE_FATAL(...) ::Zephyr::Log::GetEngineLogger()->fatal(__VA_ARGS__)

//Engine Log Macros
#define ZW_TRACE(...)        ::Zephyr::Log::GetClientLogger()->trace(__VA_ARGS__)
#define ZW_INFO(...)         ::Zephyr::Log::GetClientLogger()->info(__VA_ARGS__)
#define ZW_WARN(...)         ::Zephyr::Log::GetClientLogger()->warn(__VA_ARGS__)
#define ZW_ERROR(...)        ::Zephyr::Log::GetClientLogger()->error(__VA_ARGS__)
#define ZW_FATAL(...)        ::Zephyr::Log::GetClientLogger()->fatal(__VA_ARGS__)

//If Dist Build
//#define ZW_ENGINE_ERROR(...)
