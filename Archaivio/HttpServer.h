#pragma once
#include "../ExternalLibraries/cpp-httplib-master/httplib.h"
#include "Configurable.h"
#include <functional>

class ARCHIVIO_API HttpServer : private Configurable<Configuration>
{
private:
	// HTTP

public:
	std::unique_ptr<httplib::Server> server;

	HttpServer();

	~HttpServer();

	void StartListen();

	bool isRunning();

	void ApplyConfiguration(Configuration configuration);

	void ConfigureGet(std::string endpoint, httplib::Server::Handler handler);

	void ConfigurePost(std::string endpoint, httplib::Server::Handler handler);
};

