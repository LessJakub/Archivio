#pragma once
#include "BaseLogger.h"
class FileLogger :
    public BaseLogger
{
private:
    std::unique_ptr<FileLoggerConfiguration> configuration;
protected:
    void LogMessage(std::string message, LogMetadata& metadata) override;
public:

    void ApplyConfiguration(LoggerConfiguration& conf) override;
};

