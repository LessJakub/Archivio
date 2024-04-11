#pragma once
#include "BaseLogger.h"
class HttpLogger :
    public BaseLogger
{
private:
    std::unique_ptr<HttpLoggerConfiguration> configuration;

    std::unique_ptr<HttpClient> client;
protected:
    void LogMessage(std::string message, LogMetadata& metadata) override;
public:

    void ApplyConfiguration(LoggerConfiguration& conf) override;
};

