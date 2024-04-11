#pragma once
#include "../ExternalLibraries/cpp-httplib-master/httplib.h"
#include <memory>
#include "HttpResponse.h"
#include "Configurable.h"
#include "HttpLoggerConfiguration.h"

class ARCHIVIO_API HttpClient : public Configurable<HttpLoggerConfiguration>
{
private:
	std::unique_ptr<httplib::Client> client;

public:

	HttpClient();

	~HttpClient();

	HttpResponse Get(std::string endpoint);

	HttpResponse Post(std::string endpoint, std::string body);

	void ApplyConfiguration(HttpLoggerConfiguration conf);
};

