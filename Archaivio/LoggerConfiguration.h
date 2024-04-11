#pragma once

#include "BaseLoggerConfiguration.h"
#include "LogLevel.h"
#include "LoggerType.h"

class LoggerConfiguration : public BaseLoggerConfiguration
{
public:
	LoggerType loggerType;

	LoggerConfiguration();

	LoggerConfiguration(const LoggerConfiguration& conf);

	~LoggerConfiguration();
};