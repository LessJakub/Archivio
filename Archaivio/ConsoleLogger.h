#pragma once
#include "BaseLogger.h"
class ConsoleLogger :
    public BaseLogger
{
protected:
	void LogMessage(std::string message, LogMetadata& metadata) override;
public:

	ConsoleLogger();
	~ConsoleLogger();

	void ApplyConfiguration(LoggerConfiguration& conf) override;
};

