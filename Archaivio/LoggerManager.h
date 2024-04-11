#pragma once
#include <vector>
#include "BaseLogger.h"
#include "Configurable.h"
#include "Configuration.h"
#include "LoggerConfiguration.h"

class LoggerManager : public Configurable<Configuration>
{
private:


public:
	//should be private
	std::vector<BaseLogger*> loggers;

	BaseLogger* CreateLogger(LoggerConfiguration& configuration);

	LoggerManager();

	~LoggerManager();

	void ApplyConfiguration(Configuration conf);
};

