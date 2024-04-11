#include "pch.h"
#include "BaseLogger.h"
#include <iostream>
#include <string>
#include <format>
#include "LogMetadata.h"
#include "stream_newliner.h"
#include <fstream>
#include <ctime>   // localtime
#include <sstream> // stringstream
#include <iomanip> // put_time
#include <string>  // string
#include "utils.h"


std::string GetCurrentTimeAndDate(const char* format = DATE_FORMAT)
{
	auto now = std::chrono::system_clock::now();
	auto in_time_t = std::chrono::system_clock::to_time_t(now);

	std::stringstream ss;
	ss << std::put_time(std::localtime(&in_time_t), format);
	return ss.str();
}

BaseLogger::BaseLogger()
{
#if DEBUG
	std::cout << "Created instance of BaseLogger\n";
#endif
}

BaseLogger::BaseLogger(const BaseLogger& logger)
{
	configuration = std::make_unique<LoggerConfiguration>(*logger.configuration.get());
	LogPattern = logger.LogPattern;
}

BaseLogger::~BaseLogger()
{
#if DEBUG
	std::cout << "Deleting instance of BaseLogger\n";
#endif
}

void BaseLogger::ApplyConfiguration(LoggerConfiguration& conf)
{
	Configurable<LoggerConfiguration>::ApplyConfiguration(conf);

	LogPattern = configuration.get()->logPattern;
}

bool BaseLogger::Replace(std::string& str, const std::string& from, const std::string& to)
{
	size_t start_pos = str.find(from);

	if (start_pos == std::string::npos)
	{
		return false;
	}

	str.replace(start_pos, from.length(), to);

	return true;
}

std::string BaseLogger::ReplacePatterns(std::string pattern)
{
	std::string result = pattern;

	Replace(result, std::string(DATE_PATTERN), GetCurrentTimeAndDate(DATE_FORMAT));
	Replace(result, std::string(DATE_DAY_PATTERN), GetCurrentTimeAndDate(DATE_FORMAT_DAY));
	Replace(result, std::string(DATE_MONTH_PATTERN), GetCurrentTimeAndDate(DATE_FORMAT_MONTH));
	Replace(result, std::string(DATE_YEAR_PATTERN), GetCurrentTimeAndDate(DATE_FORMAT_YEAR));

	return result;
}

std::string BaseLogger::ReplacePatterns(std::string pattern, LogMetadata& metadata)
{
	std::string result = pattern;

	result = ReplacePatterns(result);

	Replace(result, std::string(LOG_LEVEL_PATTERN), MapLogLevelToString(metadata.level));
	Replace(result, std::string(MESSAGE_PATTERN), metadata.message);

	return result;
}


std::string BaseLogger::CreateMessage(LogMetadata& metadata)
{
	std::string message = ReplacePatterns(metadata.logPattern, metadata);

	return message;
}

void BaseLogger::LogMessage(std::string message, LogMetadata& metadata)
{
	std::cout << message << "\n";
}


void BaseLogger::Log(LogMetadata& metadata)
{
	auto conf = configuration.get();

	if (conf == nullptr) return;

	if (FilterMessage(*conf, metadata)) return;

	if (!conf->logPattern.empty()) {
		metadata.logPattern = conf->logPattern;
	}

	std::string message = CreateMessage(metadata);

	LogMessage(message, metadata);
}

