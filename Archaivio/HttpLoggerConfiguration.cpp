#include "pch.h"

HttpLoggerConfiguration::HttpLoggerConfiguration()
{
	loggerType = LoggerType::Http;
	serverHost = "localhost";
	serverPort = 8080;

#if DEBUG
	std::cout << "Initialized HttpLoggerConfiguration" << "\n";
	std::cout << loggerType << "\n";
	std::cout << serverHost << "\n";
	std::cout << serverPort << "\n";
#endif

}

HttpLoggerConfiguration::HttpLoggerConfiguration(HttpLoggerConfiguration& conf)
{
	loggerType = conf.loggerType;
	logPattern = conf.logPattern;
	logLevels = conf.logLevels;
	minimumLogLevel = conf.minimumLogLevel;
	serverHost = conf.serverHost;
	serverPort = conf.serverPort;
}

HttpLoggerConfiguration::~HttpLoggerConfiguration()
{
}
