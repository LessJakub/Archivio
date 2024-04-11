#include "pch.h"
#include "HttpLogger.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

void to_json(json& j, const LogMetadata& c) {
	j = json{};

	j["level"] = c.level;
	j["message"] = c.message;
}


void HttpLogger::LogMessage(std::string message, LogMetadata& metadata)
{
#if DEBUG
	std::cout << "-------------- Start HttpLogger::Log --------------" << "\n";
#endif

	json j = metadata;

	std::string body = j.dump();

	client.get()->Post(LOG_ENDPOINT, body);

#if DEBUG
	std::cout << "[HTTP LOGGER] ";

	BaseLogger::LogMessage(message, metadata);
#endif

#if DEBUG
	std::cout << "-------------- End HttpLogger::Log --------------" << "\n";
#endif
}

void HttpLogger::ApplyConfiguration(LoggerConfiguration& conf)
{
	BaseLogger::ApplyConfiguration(conf);

	HttpLoggerConfiguration& configuration = static_cast<HttpLoggerConfiguration&>(conf);

	this->configuration = std::make_unique<HttpLoggerConfiguration>(configuration);

	this->client = std::make_unique<HttpClient>();

	this->client.get()->ApplyConfiguration(configuration);
}
