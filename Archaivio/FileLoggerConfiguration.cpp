#include "pch.h"

FileLoggerConfiguration::FileLoggerConfiguration()
{
	loggerType = LoggerType::File;
#if DEBUG
	std::cout << "Initialized FileLoggerConfiguration" << "\n";
	std::cout << loggerType << "\n";
	std::cout << fileNamePattern << "\n";
#endif
}

FileLoggerConfiguration::FileLoggerConfiguration(FileLoggerConfiguration& conf)
{
	fileNamePattern = conf.fileNamePattern;
	filePath = conf.filePath;
	loggerType = conf.loggerType;
	logPattern = conf.logPattern;
	logLevels = conf.logLevels;
	minimumLogLevel = conf.minimumLogLevel;
}

FileLoggerConfiguration::~FileLoggerConfiguration()
{
}