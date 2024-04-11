#include "pch.h"
#include "Logger.h"
#include <string>
#include <iostream>
#include "ConfigurationFunctions.h"
#include <thread>
#include <nlohmann/json.hpp>
#include "utils.h"

using json = nlohmann::json;

void from_json(const json& j, LogMetadata& c) {
	j.at("level").get_to(c.level);
	j.at("message").get_to(c.message);
}

void Logger::Log(LogMetadata& metadata)
{
	auto conf = configuration.get();

	if (conf == nullptr) return;

	if(FilterMessage(*conf, metadata)) return;

	if (metadata.logPattern.empty() && !conf->logPattern.empty()) {
		metadata.logPattern = conf->logPattern;
	}

	std::vector<BaseLogger*> loggers = manager.get()->loggers;

	for (const auto& logger : loggers)
	{
		logger->Log(metadata);
	}
}

void Logger::LoadConfiguration(std::string configPath)
{
	std::ifstream file(configPath);
	if (file.is_open()) {

#if DEBUG
		std::cout << "File: " << configPath << " is open." << "\n";
#endif
		configuration = std::make_unique<Configuration>(ReadFile(configPath));
	}
	else {

		std::cout << "File: " << configPath << " can't be accessed." << "\n";

		configuration = std::make_unique<Configuration>();

#if DEBUG
		std::cout << "Saving configuration to file: " << configPath << "\n";
#endif
		ToFile(*configuration.get(), configPath);
	}
}

void Logger::ProcessResponse(std::string response)
{
}

Logger::Logger(std::string configPath)
{
	LoadConfiguration(configPath);

	manager = std::make_unique<LoggerManager>();

	auto conf = configuration.get();
	manager.get()->ApplyConfiguration(*conf);

#if DEBUG
	std::cout << "Is server configuration: " << conf->isServerConfiguration << "\n";
#endif
	if (conf->isServerConfiguration) {
		server = std::make_unique<HttpServer>();

		auto svr = server.get();

		int tmp = 0;

		svr->ApplyConfiguration(*conf);

		svr->ConfigurePost(LOG_ENDPOINT, [&](const httplib::Request& req, httplib::Response& res) {

			//set server side configuration, remove logPattern from http config
			json data = json::parse(req.body);

			LogMetadata metadata = data;

			Log(metadata);
		});

		serverThread = std::make_unique<std::thread>(&HttpServer::StartListen, svr);
	}
	
}

Logger::~Logger()
{
	auto svr = server.get();

	if (svr != nullptr) {
		auto httpSvr = svr->server.get();

		if (httpSvr != nullptr) {
			httpSvr->stop();
		}
	}

	auto thread = serverThread.get();

	if(thread != nullptr) {
		serverThread.get()->join();
	}
}

void Logger::Debug(std::string message)
{
	LogMetadata metadata(LogLevel::Debug, message);

	Log(metadata);
}

void Logger::Info(std::string message)
{
	LogMetadata metadata(LogLevel::Info, message);

	Log(metadata);
}

void Logger::Warning(std::string message)
{
	LogMetadata metadata(LogLevel::Warning, message);

	Log(metadata);
}


void Logger::Error(std::string message)
{
	LogMetadata metadata(LogLevel::Error, message);

	Log(metadata);
}

//Logger global;