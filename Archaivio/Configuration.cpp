#include "pch.h"
#include "Configuration.h"
#include <fstream>

Configuration::Configuration()
{
	ConsoleLoggerConfiguration* consoleConfig = new ConsoleLoggerConfiguration();
	FileLoggerConfiguration* fileConfig = new FileLoggerConfiguration();
	HttpLoggerConfiguration* httpConfig = new HttpLoggerConfiguration();

	loggersConfiguration.push_back(consoleConfig);
	loggersConfiguration.push_back(fileConfig);
	loggersConfiguration.push_back(httpConfig);
}

Configuration::~Configuration()
{
}

Configuration::Configuration(const Configuration& conf)
{
	logPattern = conf.logPattern;
	logLevels = conf.logLevels;
	minimumLogLevel = conf.minimumLogLevel;
	isServerConfiguration = conf.isServerConfiguration;
	loggersConfiguration = conf.loggersConfiguration;
	serverHost = conf.serverHost;
	serverPort = conf.serverPort;
}

//json& to_json(const Configuration& config)
//{
//	json j = json{
//		//{"serverLoggerType", config.serverLogerType},
//		//{"loggersConfiguration", config.loggersConfiguration}
//	};
//
//	return j;
//}
//
//void from_json(json& j, const Configuration& config) {
//
//}