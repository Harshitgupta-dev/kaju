#include "kpch.h"
#include "Log.h"

namespace kaju {
	std::shared_ptr<spdlog::logger> Log::coreLogger;
	std::shared_ptr<spdlog::logger> Log::clientLogger;

	void Log::init() {
		spdlog::set_pattern("%^[%T] %n: %v%$");
		Log::coreLogger = spdlog::stdout_color_mt("KAJU");
		coreLogger->set_level(spdlog::level::trace);
		Log::clientLogger = spdlog::stdout_color_mt("APP");
		clientLogger->set_level(spdlog::level::trace);
	}

	std::shared_ptr<spdlog::logger>& Log::getCoreLogger() { return Log::coreLogger; }
	std::shared_ptr<spdlog::logger>& Log::getClientLogger() { return Log::clientLogger; }
}

