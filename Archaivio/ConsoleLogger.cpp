#include "pch.h"
#include "ConsoleLogger.h"
#include <windows.h>
#include <stdio.h>
#include <tchar.h>

void ConsoleLogger::LogMessage(std::string message, LogMetadata& metadata)
{
#if DEBUG
	std::cout << "-------------- Start ConsoleLogger::Log --------------" << "\n";
#endif

	std::cout << message << "\n";

#if DEBUG
	std::cout << "[CONSOLE LOGGER] ";

	BaseLogger::LogMessage(message, metadata);
#endif

#if DEBUG
	std::cout << "-------------- End ConsoleLogger::Log --------------" << "\n";
#endif
}

ConsoleLogger::ConsoleLogger()
{
}

ConsoleLogger::~ConsoleLogger()
{
}

void ConsoleLogger::ApplyConfiguration(LoggerConfiguration& conf)
{
	BaseLogger::ApplyConfiguration(conf);

	ConsoleLoggerConfiguration& configuration = static_cast<ConsoleLoggerConfiguration&>(conf);
}
