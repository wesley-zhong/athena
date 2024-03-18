#include "XLog.h"

void xLogInitLog(LogLevel logLevel)
{
	switch (logLevel)
	{
	case LogLevel::LL_DEBUG:
		spdlog::set_level(spdlog::level::debug);
		break;
	case LogLevel::LL_INFO:
		spdlog::set_level(spdlog::level::info);
		break;
	case LogLevel::LL_WARNING:
		spdlog::set_level(spdlog::level::info);
		break;
	case LogLevel::LL_ERROR:
		spdlog::set_level(spdlog::level::info);
		break;

	default:
		break;
	}
	spdlog::set_pattern("[%H:%M:%S %z] [%^%L%$] [thread %t] %v");
}