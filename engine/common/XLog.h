#ifndef XLOG_H_
#define XLOG_H_
#include "spdlog/spdlog.h"

#define LOG_MAX_SIZE 1073741824
enum LogLevel
{
	LL_DEBUG,
	LL_INFO,
	LL_WARNING,
	LL_ERROR,
};

void xLogInitLog(LogLevel logLevel, const std::string &fileName);
//extern spdlog::logger *pSpdLog;

#define DEBUG_LOG(...) spdlog::debug(__VA_ARGS__)
#define INFO_LOG(...) spdlog::info(__VA_ARGS__)
#define WARN_LOG(...) spdlog::warn(__VA_ARGS__)
#define ERR_LOG(...) spdlog::error(__VA_ARGS__)

#endif
