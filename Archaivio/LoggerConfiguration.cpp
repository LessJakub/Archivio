#include "pch.h"


LoggerConfiguration::LoggerConfiguration()
{
}

LoggerConfiguration::LoggerConfiguration(const LoggerConfiguration& conf)
{
	logPattern = conf.logPattern;
	logLevels = conf.logLevels;
	minimumLogLevel = conf.minimumLogLevel;
	loggerType = conf.loggerType;
}

LoggerConfiguration::~LoggerConfiguration()
{
}
