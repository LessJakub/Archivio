#pragma once
#include "LoggerConfiguration.h"
#include "HttpConfiguration.h"

class ARCHIVIO_API HttpLoggerConfiguration : public LoggerConfiguration, public HttpConfiguration
{
public:

    HttpLoggerConfiguration();

    HttpLoggerConfiguration(HttpLoggerConfiguration& conf);

    ~HttpLoggerConfiguration();

};

