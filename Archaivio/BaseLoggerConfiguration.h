#pragma once
#include "LogLevel.h"
#include <string>
#include <vector>

class BaseLoggerConfiguration
{
public:
	std::string logPattern = std::string(DATE_PATTERN) + ": [" + std::string(LOG_LEVEL_PATTERN) + "] " + std::string(MESSAGE_PATTERN);

	std::vector<LogLevel> logLevels = std::vector<LogLevel>(1, LogLevel::AllLevels);

	LogLevel minimumLogLevel = LogLevel::AllLevels;

	BaseLoggerConfiguration();

	~BaseLoggerConfiguration();

	BaseLoggerConfiguration(const BaseLoggerConfiguration& conf);
};