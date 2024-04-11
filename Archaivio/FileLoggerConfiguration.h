#pragma once
#include "LoggerConfiguration.h"

class ARCHIVIO_API FileLoggerConfiguration : public LoggerConfiguration
{
public:

    std::string fileNamePattern = std::string(DATE_PATTERN) + ".log";

    std::string filePath = std::string(DEFAULT_FILE_PATH);

    FileLoggerConfiguration();
    FileLoggerConfiguration(FileLoggerConfiguration& conf);
    ~FileLoggerConfiguration();

};

