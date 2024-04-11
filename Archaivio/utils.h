#pragma once

bool FilterMinimumLevel(LogLevel minimumLevel, LogLevel level);

bool FilterAllowedLevel(std::vector<LogLevel> allowedLevels, LogLevel level);

bool FilterMessage(Configuration& configuration, LogMetadata metadata);

bool FilterMessage(LoggerConfiguration& configuration, LogMetadata metadata);

bool FilterMessage(BaseLoggerConfiguration& configuration, LogMetadata metadata);

const char* MapLogLevelToString(LogLevel& v);