#include "pch.h"
#include "LoggerManager.h"
#include "ConsoleLogger.h"
#include "FileLogger.h"
#include "HttpLogger.h"

LoggerManager::LoggerManager()
{

}

LoggerManager::~LoggerManager()
{
}

void LoggerManager::ApplyConfiguration(Configuration conf)
{
	configuration = std::make_unique<Configuration>(conf);

	std::vector<LoggerConfiguration*> loggersConfigurations = configuration->loggersConfiguration;

	for (LoggerConfiguration* config : loggersConfigurations)
	{
#if DEBUG
		std::cout << "Initializing logger" << "\n";
		std::cout << "Type: " << config->loggerType << "\n";
		std::cout << "Pattern: " << config->logPattern << "\n";
#endif

		BaseLogger* logger = CreateLogger(*config);

		logger->ApplyConfiguration(*config);

		loggers.push_back(logger);
	}
}


BaseLogger* LoggerManager::CreateLogger(LoggerConfiguration& configuration)
{

	BaseLogger* logger = nullptr;

	switch (configuration.loggerType)
	{
	case File:
		logger = new FileLogger();
		break;
	case Console:
		logger = new ConsoleLogger();
		break;
	case Http:
		logger = new HttpLogger();
		break;
	default:
#if DEBUG
		std::cout << "Unhandled logger type" << "\n";
		std::cout << configuration.loggerType << "\n";
		std::cout << "skipping" << "\n";
#endif
		break;
	}

	return logger;
}