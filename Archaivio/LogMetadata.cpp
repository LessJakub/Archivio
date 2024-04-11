#include "pch.h"
#include "LogMetadata.h"


LogMetadata::LogMetadata(LogMetadata& metadata)
{
	level = metadata.level;
	message = metadata.level;
	logPattern = metadata.logPattern;
}

LogMetadata::~LogMetadata()
{
}


LogMetadata::LogMetadata()
{
}

LogMetadata::LogMetadata(LogLevel v) : level(v)
{
}

LogMetadata::LogMetadata(LogLevel v, std::string m) : level(v), message(m)
{
}

//LogMetadata& LogMetadata::operator << (std::string message)
//{
//	this->message = message;
//
//	return *this;
//}
//
//LogMetadata INFO(LogLevel::Info);
//
//LogMetadata ERROR(LogLevel::Error);
//
//LogMetadata WARNING(LogLevel::Warning);