#include "pch.h"
#include "FileLogger.h"
#include <iostream>
#include <filesystem>

char specialCharacters[] = { '<', '>', ':', '"', '\\', '/', '|', '?', '\0' };

void FileLogger::LogMessage(std::string message, LogMetadata& metadata)
{
#if DEBUG
	std::cout << "-------------- Start FileLogger::Log --------------" << "\n";
#endif

	FileLoggerConfiguration& conf = static_cast<FileLoggerConfiguration&>(*configuration.get());

	std::string fileNamePattern = conf.fileNamePattern;

	std::string fileName = ReplacePatterns(fileNamePattern, metadata);

	for (int i = 0; specialCharacters[i] != '\0'; ++i) {
		while (Replace(fileName, std::string(1, specialCharacters[i]), "_"));
	}

#if DEBUG
	std::cout << "File name: " << fileName << "\n";
#endif

	std::string path = conf.filePath;

#if DEBUG
	std::cout << "Path: " << path << "\n";

#endif

	if (path.length() > 0) {
		std::filesystem::create_directories(path);
	}

	std::string filePath = (path.length() > 0 ? path + "\\" : "") + fileName;

#if DEBUG
	std::cout << "File path: " << filePath << "\n";
#endif

	std::ofstream file(filePath, std::ios::app);

	if (file.is_open()) {
		file << message << std::endl;
		file.close();
	}

#if DEBUG
	std::cout << "[FILE LOGGER] ";

	BaseLogger::LogMessage(message, metadata);
#endif

#if DEBUG
	std::cout << "-------------- End FileLogger::Log --------------" << "\n";
#endif
}

void FileLogger::ApplyConfiguration(LoggerConfiguration& conf)
{
	BaseLogger::ApplyConfiguration(conf);

	FileLoggerConfiguration& configuration = static_cast<FileLoggerConfiguration&>(conf);

	this->configuration = std::make_unique<FileLoggerConfiguration>(configuration);
}
