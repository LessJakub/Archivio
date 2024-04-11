#include "pch.h"
#include "HttpClient.h"


HttpClient::HttpClient()
{
}

HttpClient::~HttpClient()
{
}

HttpResponse HttpClient::Get(std::string endpoint)
{
	auto res = client.get()->Get(endpoint);

	res->status;
	res->body;

	return HttpResponse();
}

HttpResponse HttpClient::Post(std::string endpoint, std::string body)
{

	auto res = client.get()->Post(endpoint, body.size(),
		[&](size_t offset, size_t length, httplib::DataSink& sink) {
			sink.write(body.data() + offset, length);
			return true; // return 'false' if you want to cancel the request.
		},
		"text/plain");

	return HttpResponse(); 
}

void HttpClient::ApplyConfiguration(HttpLoggerConfiguration conf)
{
	Configurable<HttpLoggerConfiguration>::ApplyConfiguration(conf);

	client = std::make_unique<httplib::Client>(conf.serverHost, conf.serverPort);
}
