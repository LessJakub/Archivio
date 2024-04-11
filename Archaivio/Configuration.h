#pragma once
#include <string>
#include "BaseLoggerConfiguration.h"
#include "LoggerConfiguration.h"
#include "HttpConfiguration.h"
#include <vector>

class ARCHIVIO_API Configuration : public BaseLoggerConfiguration, public HttpConfiguration
{
public:

	bool isServerConfiguration = false;

	std::vector<LoggerConfiguration*> loggersConfiguration;

	Configuration();

	~Configuration();

	Configuration(const Configuration& conf);

	//void ReadFile(std::string path);

	//void ToFile(std::string path);

	//void operator=(Configuration& c);
};