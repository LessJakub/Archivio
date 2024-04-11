#pragma once

//#define DEBUG true


#ifdef ARCHIVIO_EXPORTS
#define ARCHIVIO_API __declspec(dllexport)
#else
#define ARCHIVIO_API __declspec(dllimport)
#endif

#define DATE_PATTERN "{DATE}"
#define DATE_DAY_PATTERN "{DATE_DAY}"
#define DATE_MONTH_PATTERN "{DATE_MONTH}"
#define DATE_YEAR_PATTERN "{DATE_YEAR}"

#define DATE_FORMAT "%Y-%m-%d %X"
#define DATE_FORMAT_DAY "%Y-%m-%d"
#define DATE_FORMAT_MONTH "%Y-%m"
#define DATE_FORMAT_YEAR "%Y"

#define LOG_LEVEL_PATTERN "{LOG_LEVEL}"

#define MESSAGE_PATTERN "{MESSAGE}"

#define DEFAULT_FILE_PATH "logs"

#define LOG_ENDPOINT "LOG"

//To enable std::localtime
#define _CRT_SECURE_NO_DEPRECATE