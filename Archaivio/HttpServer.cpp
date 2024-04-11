#include "pch.h"
#include "HttpServer.h"


HttpServer::HttpServer()
{
}

HttpServer::~HttpServer()
{
	auto svr = server.get();

	if (svr != nullptr) {

		svr->stop();
	}
}

void HttpServer::StartListen()
{
	auto config = configuration.get();
#if DEBUG
	std::cout << "Starting listining: " << config->serverHost << ":" << config->serverPort << "\n";
#endif

	auto srv = server.get();

	if (srv != nullptr) {
		srv->listen(config->serverHost, config->serverPort);
	}
}

bool HttpServer::isRunning()
{
	return server.get()->is_running();
}

void HttpServer::ApplyConfiguration(Configuration configuration)
{
	Configurable<Configuration>::ApplyConfiguration(configuration);

	server = std::make_unique<httplib::Server>();
}

void HttpServer::ConfigureGet(std::string endpoint, httplib::Server::Handler handler)
{
	server.get()->Get(endpoint, handler);
}

void HttpServer::ConfigurePost(std::string endpoint, httplib::Server::Handler handler)
{
	server.get()->Post(endpoint, handler);
}
