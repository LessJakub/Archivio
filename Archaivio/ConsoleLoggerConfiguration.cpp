#include "pch.h"

ConsoleLoggerConfiguration::ConsoleLoggerConfiguration()
{
	loggerType = LoggerType::Console;
#if DEBUG
	std::cout << "Initialized HttpLoggerConfiguration" << "\n";
	std::cout << loggerType << "\n";
	std::cout << consoleName << "\n";;
#endif
}

ConsoleLoggerConfiguration::ConsoleLoggerConfiguration(ConsoleLoggerConfiguration& conf)
{
	loggerType = conf.loggerType;
	logPattern = conf.logPattern;
	logLevels = conf.logLevels;
	minimumLogLevel = conf.minimumLogLevel;
	consoleName = conf.consoleName;
}

ConsoleLoggerConfiguration::~ConsoleLoggerConfiguration()
{
}