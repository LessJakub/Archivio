#pragma once
#include "LoggerManager.h"
#include "LogMetadata.h"
#include "HttpServer.h"

class ARCHIVIO_API Logger
{
private:

	std::unique_ptr<LoggerManager> manager;

	std::unique_ptr<HttpServer> server;

	std::unique_ptr<Configuration> configuration;

	void Log(LogMetadata& metadata);

	void LoadConfiguration(std::string configPath);

	void ProcessResponse(std::string response);

	std::unique_ptr<std::thread> serverThread;

public:

	Logger(std::string configPath = "archivioConfig.json");

	~Logger();

	void Info(std::string message);

	void Error(std::string message);

	void Warning(std::string message);

	void Debug(std::string message);
};