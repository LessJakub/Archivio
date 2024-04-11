#pragma once
#include <string>
#include "LogMetadata.h"
#include "Configurable.h"

class BaseLogger : public Configurable<LoggerConfiguration>
{
protected:
	std::string LogPattern;

	bool Replace(std::string& str, const std::string& from, const std::string& to);

	std::string ReplacePatterns(std::string pattern);

	std::string ReplacePatterns(std::string pattern, LogMetadata& metadata);

	std::string CreateMessage(LogMetadata& metadata);

	virtual void LogMessage(std::string message, LogMetadata& metadata);
public:
	BaseLogger();

	BaseLogger(const BaseLogger& logger);

	~BaseLogger();

	void Log(LogMetadata& metadata);

	virtual void ApplyConfiguration(LoggerConfiguration& conf);
};
