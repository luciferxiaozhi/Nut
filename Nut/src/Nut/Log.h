#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Nut {
	
	class NUT_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define NUT_CORE_TRACE(...)		::Nut::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define NUT_CORE_INFO(...)		::Nut::Log::GetCoreLogger()->info(__VA_ARGS__)
#define NUT_CORE_WARN(...)		::Nut::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define NUT_CORE_ERROR(...)		::Nut::Log::GetCoreLogger()->error(__VA_ARGS__)
#define NUT_CORE_FATAL(...)		::Nut::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define NUT_TRACE(...)			::Nut::Log::GetClientLogger()->trace(__VA_ARGS__)
#define NUT_INFO(...)			::Nut::Log::GetClientLogger()->info(__VA_ARGS__)
#define NUT_WARN(...)			::Nut::Log::GetClientLogger()->warn(__VA_ARGS__)
#define NUT_ERROR(...)			::Nut::Log::GetClientLogger()->error(__VA_ARGS__)
#define NUT_FATAL(...)			::Nut::Log::GetClientLogger()->critical(__VA_ARGS__)