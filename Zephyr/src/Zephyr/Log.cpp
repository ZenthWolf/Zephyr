#include "spdlog/sinks/stdout_color_sinks.h"
#include "Log.h"

namespace Zephyr
{

	std::shared_ptr<spdlog::logger> Log::engineLogger;
	std::shared_ptr<spdlog::logger> Log::clientLogger;

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

		engineLogger = spdlog::stdout_color_mt("ZEPHYR");
		engineLogger->set_level(spdlog::level::trace);

		clientLogger = spdlog::stdout_color_mt("CLIENT");
		clientLogger->set_level(spdlog::level::trace);
	}
}