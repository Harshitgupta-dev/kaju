#pragma once
#include "core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace kaju {
	class KAJU_API Log
	{
	public:
		static void init();
		static std::shared_ptr<spdlog::logger>& getCoreLogger();
		static std::shared_ptr<spdlog::logger>& getClientLogger();

	private:
		static std::shared_ptr<spdlog::logger> coreLogger;
		static std::shared_ptr<spdlog::logger> clientLogger;
	};
}
#define kaju_core_trace(...) ::kaju::Log::getCoreLogger()->trace(__VA_ARGS__)
#define kaju_core_info(...) ::kaju::Log::getCoreLogger()->info(__VA_ARGS__)
#define kaju_core_warn(...) ::kaju::Log::getCoreLogger()->warn(__VA_ARGS__)
#define kaju_core_error(...) ::kaju::Log::getCoreLogger()->error(__VA_ARGS__)
#define kaju_core_critical(...) ::kaju::Log::getCoreLogger()->critical(__VA_ARGS__)

#define kaju_trace(...) ::kaju::Log::getClientLogger()->trace(__VA_ARGS__)
#define kaju_info(...) ::kaju::Log::getClientLogger()->info(__VA_ARGS__)
#define kaju_warn(...) ::kaju::Log::getClientLogger()->warn(__VA_ARGS__)
#define kaju_error(...) ::kaju::Log::getClientLogger()->error(__VA_ARGS__)
#define kaju_critical(...) ::kaju::Log::getClientLogger()->critical(__VA_ARGS__)