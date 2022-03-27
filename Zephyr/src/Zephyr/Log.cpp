#include "spdlog/sinks/stdout_color_sinks.h"
#include "Log.h"

namespace Zephyr
{

	std::shared_ptr<spdlog::logger> Log::s_EngineLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::Init()
	{
		//See spdlog wiki for more pattern formats
		//%^: start color range
		//%l: level severity
		//%T: ISO 8601 time (HH:MM:SS) in 24-Hour time
		//%n: logger's name
		//%v: text to log
		//%$: end color range
		spdlog::set_pattern("%^[%l] (%T) %n: %v%$");

		s_EngineLogger = spdlog::stdout_color_mt("ZEPHYR");
		s_EngineLogger->set_level(spdlog::level::trace);

		s_ClientLogger = spdlog::stdout_color_mt("CLIENT");
		s_ClientLogger->set_level(spdlog::level::trace);
	}
}