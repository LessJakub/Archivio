#include "pch.h"
#include "BaseLoggerConfiguration.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;


BaseLoggerConfiguration::BaseLoggerConfiguration()
{
}

BaseLoggerConfiguration::~BaseLoggerConfiguration()
{
}

BaseLoggerConfiguration::BaseLoggerConfiguration(const BaseLoggerConfiguration& conf)
{
	logPattern = conf.logPattern;
	logLevels = conf.logLevels;
	minimumLogLevel = conf.minimumLogLevel;
}