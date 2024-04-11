#pragma once
#include <string>
class ILogger
{
    //private static ILogger instance = new ILogger();

public:
    virtual void Log(std::string message);

    virtual void Error(std::string message);
};

