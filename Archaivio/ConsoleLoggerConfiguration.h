#pragma once
#include "LoggerConfiguration.h"
class ARCHIVIO_API ConsoleLoggerConfiguration : public LoggerConfiguration
{
public:
    std::string consoleName = "ArchivioLogger";

    ConsoleLoggerConfiguration();
    ConsoleLoggerConfiguration(ConsoleLoggerConfiguration& conf);
    ~ConsoleLoggerConfiguration();

};

