#pragma once
#include "LogLevel.h"
#include <string>

class LogMetadata
{
public:
	LogLevel level;

	std::string message;

	std::string logPattern;

	LogMetadata();

	LogMetadata(LogLevel level);

	LogMetadata(LogMetadata& metadata);

	~LogMetadata();

	LogMetadata(LogLevel v, std::string m);

	/*LogMetadata& operator << (std::string message);*/
};

//static LogMetadata INFO(LogLevel::Info);
//
//static LogMetadata ERROR(LogLevel::Error);
//
//static LogMetadata WARNING(LogLevel::Warning);