#include "pch.h"
#include "ConfigurationFunctions.h"
#include <stdexcept>
#include <nlohmann/json.hpp>
#include "LogLevel.h"

using json = nlohmann::json;

template<class T>
void nullableFromJson(const json& j, std::string jsonName, T& value) {
	if (j.contains(jsonName)) {
		j.at(jsonName).get_to(value);
	}
	else {
		if constexpr (std::is_same_v<T, std::string>) {
			value = ""; // Assign an empty string for T = std::string
		}
		else if  constexpr (std::is_same_v<T, int>) {
			value = 0;
		}
		else if  constexpr (std::is_same_v<T, std::vector<LogLevel>>) {
			value = std::vector<LogLevel>();
		}
		else if  constexpr (std::is_same_v<T, LogLevel>) {
			value = AllLevels;
		}
	}
}

template<class T>
void nullableToJson(json& j, std::string jsonName, const T& value) {

	bool isDefault = true;

	if constexpr (std::is_same_v<T, std::string>) {
		isDefault = value.empty();
	}
	else if  constexpr (std::is_same_v<T, int>) {
		isDefault = value == 0;
	}
	else if  constexpr (std::is_same_v<T, std::vector<LogLevel>>) {
		isDefault = value.empty();
	}
	else if  constexpr (std::is_same_v<T, LogLevel>) {
		isDefault = value == AllLevels;
	}

	if (!isDefault) {
		if (j.empty()) {
			j = json{};
		}

		j[jsonName] = value;
	}
}

void to_json(json& j, const BaseLoggerConfiguration& c) {

	if (j.empty()) {
		j = json{};
	}

	nullableToJson<std::string>(j, "logPattern", c.logPattern);
	nullableToJson<std::vector<LogLevel>>(j, "logLevels", c.logLevels);
	nullableToJson<LogLevel>(j, "minimumLogLevel", c.minimumLogLevel);
}

void from_json(const json& j, BaseLoggerConfiguration& c) {

	nullableFromJson<std::string>(j, "logPattern", c.logPattern);
	nullableFromJson<std::vector<LogLevel>>(j, "logLevels", c.logLevels);
	nullableFromJson<LogLevel>(j, "minimumLogLevel", c.minimumLogLevel);
}

void to_json(json& j, const LoggerConfiguration& c) {
	const BaseLoggerConfiguration* base = static_cast<const BaseLoggerConfiguration*>(&c);
	to_json(j, *base);

	if (j.empty()) {
		j = json{};
	}

	j["loggerType"] = c.loggerType;
}

void from_json(const json& j, LoggerConfiguration& c) {
	BaseLoggerConfiguration* base = static_cast<BaseLoggerConfiguration*>(&c);
	from_json(j, *base);

	j.at("loggerType").get_to(c.loggerType);
}

void to_json(json& j, const ConsoleLoggerConfiguration& c) {
	const LoggerConfiguration* base = static_cast<const LoggerConfiguration*>(&c);
	to_json(j, *base);

	if (j.empty()) {
		j = json{};
	}

	nullableToJson<std::string>(j, "consoleName", c.consoleName);
}

void from_json(const json& j, ConsoleLoggerConfiguration& c) {
	LoggerConfiguration* base = static_cast<LoggerConfiguration*>(&c);
	from_json(j, *base);

	nullableFromJson<std::string>(j, "consoleName", c.consoleName);
}

void to_json(json& j, const FileLoggerConfiguration& c) {
	const LoggerConfiguration* base = static_cast<const LoggerConfiguration*>(&c);
	to_json(j, *base);

	if (j.empty()) {
		j = json{};
	}


	nullableToJson<std::string>(j, "fileNamePattern", c.fileNamePattern);
	nullableToJson<std::string>(j, "filePath", c.filePath);
}

void from_json(const json& j, FileLoggerConfiguration& c) {
	LoggerConfiguration* base = static_cast<LoggerConfiguration*>(&c);
	from_json(j, *base);

	nullableFromJson<std::string>(j, "fileNamePattern", c.fileNamePattern);
	nullableFromJson<std::string>(j, "filePath", c.filePath);
}

void to_json(json& j, const HttpLoggerConfiguration& c) {
	/*const LoggerConfiguration* base = static_cast<const LoggerConfiguration*>(&c);
	to_json(j, *base);*/

	if (j.empty()) {
		j = json{};
	}

	j["loggerType"] = c.loggerType;

	nullableToJson<std::string>(j, "serverHost", c.serverHost);
	nullableToJson<int>(j, "serverPort", c.serverPort);

}

void from_json(const json& j, HttpLoggerConfiguration& c) {
	/*BaseLoggerConfiguration* base = static_cast<LoggerConfiguration*>(&c);
	from_json(j, *base);*/

	j.at("loggerType").get_to(c.loggerType);

	nullableFromJson<std::string>(j, "serverHost", c.serverHost);
	nullableFromJson<int>(j, "serverPort", c.serverPort);
}

void to_json(json& j, LoggerConfiguration* c) {

	LoggerType type = c->loggerType;

	if (type == File) {
		FileLoggerConfiguration* file = static_cast<FileLoggerConfiguration*>(c);
		to_json(j, *file);
	}
	else if (type == Console) {
		ConsoleLoggerConfiguration* console = static_cast<ConsoleLoggerConfiguration*>(c);
		to_json(j, *console);
	}
	else if (type == Http) {
		HttpLoggerConfiguration* http = static_cast<HttpLoggerConfiguration*>(c);
		to_json(j, *http);
	}
}

void from_json(const json& j, LoggerConfiguration*& c) {

	LoggerType type;

	j.at("loggerType").get_to(type);


	if (type == File) {
		FileLoggerConfiguration* file = c == nullptr ? new FileLoggerConfiguration() : static_cast<FileLoggerConfiguration*>(c);
		from_json(j, *file);
		c = file;

	}
	else if (type == Console) {
		ConsoleLoggerConfiguration* console = c == nullptr ? new ConsoleLoggerConfiguration() : static_cast<ConsoleLoggerConfiguration*>(c);
		from_json(j, *console);
		c = console;

	}
	else if (type == Http) {
		HttpLoggerConfiguration* http = c == nullptr ? new HttpLoggerConfiguration() : static_cast<HttpLoggerConfiguration*>(c);
		from_json(j, *http);
		c = http;
	}
}

void to_json(json& j, const Configuration& c) {
	const BaseLoggerConfiguration* base = static_cast<const BaseLoggerConfiguration*>(&c);
	to_json(j, *base);

	if (j.empty()) {
		j = json{};
	}

	nullableToJson<bool>(j, "isServerConfiguration", c.isServerConfiguration);
	nullableToJson<std::string>(j, "serverHost", c.serverHost);
	nullableToJson<int>(j, "serverPort", c.serverPort);

	//if (!j.contains("logLevels")) {
	//	j["logLevels"] = c.logLevels;
	//}

	j["loggersConfiguration"] = c.loggersConfiguration;
}

void from_json(const json& j, Configuration& c) {
	BaseLoggerConfiguration* base = static_cast<BaseLoggerConfiguration*>(&c);
	from_json(j, *base);


	nullableFromJson<bool>(j, "isServerConfiguration", c.isServerConfiguration);
	nullableFromJson<std::string>(j, "serverHost", c.serverHost);
	nullableFromJson<int>(j, "serverPort", c.serverPort);

	//j.at("logLevels").get_to(c.logLevels);

	j.at("loggersConfiguration").get_to(c.loggersConfiguration);
}

Configuration ReadFile(std::string path)
{
	try {
#if DEBUG
		std::cout << "Reading file: " << path << "\n";
#endif

		std::ifstream f(path);

#if DEBUG
		std::cout << "Parsing file to json" << "\n";
#endif

		json data = json::parse(f);

#if DEBUG
		std::cout << "Casting json to Configruation" << "\n";
#endif

		Configuration c = data;

		return c;
	}
	catch  (std::exception ex){
		std::string message = "An exception occured while parsing json file. Please verify file content. " + std::string(ex.what());

#if DEBUG
		std::cout << message << "\n";
#endif

		throw std::runtime_error(message);
	}

	Configuration def;

	return def;
}

void ToFile(Configuration& c, std::string path)
{
	json j = c;

	std::ofstream file(path);
	file << j.dump(4);
}