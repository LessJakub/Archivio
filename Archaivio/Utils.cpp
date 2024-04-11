#include "pch.h"
#include "utils.h"

bool FilterMinimumLevel(LogLevel minimumLevel, LogLevel level)
{
	if (minimumLevel > level) {
#if DEBUG
		std::cout << "Message filtered by minimum level" << "\n";
		std::cout << "Minimum level: " << minimumLevel << " Level: " << level << "\n";
#endif
		return true;
	}

	return false;
}

bool FilterAllowedLevel(std::vector<LogLevel> allowedLevels, LogLevel level)
{
	if (allowedLevels.size() == 0)return false;

	for (int i = 0; i < allowedLevels.size(); i++) {
		if (allowedLevels[i] == AllLevels) return false;
	}

	for (int i = 0; i < allowedLevels.size(); i++) {
		if (level == allowedLevels[i]) return false;
	}

#if DEBUG
	std::cout << "Message filtered by allowed level" << "\n";
	std::cout << "Level: " << level << "\n";
#endif
	return true;
}

bool FilterMessage(Configuration& configuration, LogMetadata metadata)
{
	BaseLoggerConfiguration* conf = static_cast<BaseLoggerConfiguration*>(&configuration);
	return FilterMessage(*conf, metadata);
}

bool FilterMessage(LoggerConfiguration& configuration, LogMetadata metadata)
{
	BaseLoggerConfiguration* conf = static_cast<BaseLoggerConfiguration*>(&configuration);
	return FilterMessage(*conf, metadata);
}

bool FilterMessage(BaseLoggerConfiguration& configuration, LogMetadata metadata)
{
	if (FilterMinimumLevel(configuration.minimumLogLevel, metadata.level)) return true;

	auto allowedLevels = configuration.logLevels;

	if (FilterAllowedLevel(allowedLevels, metadata.level)) return true;

	return false;
}

const char* MapLogLevelToString(LogLevel& v)
{
	switch (v)
	{
	case Info: return "INFO";
	case Warning: return "WARNING";
	case Error: return "ERROR";
	case Debug: return "DEBUG";
	default: return "UNKNOWN LOG LEVEL";
	}
}
