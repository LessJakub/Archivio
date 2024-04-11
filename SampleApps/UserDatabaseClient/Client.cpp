#include "Client.h"
#include "../UserDatabase/jsonutils.h"
#include "../UserDatabase/LoginForm.h"
#include <nlohmann/json.hpp>
#include "utils.h"

using json = nlohmann::json;


Client::Client()
{
}

Client::~Client()
{
}


void Client::Login(std::string username, std::string password, User& user)
{
	
	LoginForm form;
	form.Username = username;
	form.Password = password;

	json j = form;

	std::string body = j.dump();

	auto res = client.Post("login", body.size(),
		[&](size_t offset, size_t length, httplib::DataSink& sink) {
			sink.write(body.data() + offset, length);
			return true; // return 'false' if you want to cancel the request.
		},
		"text/plain");

	try {
		if (res != nullptr && res->body.size() > 0) {
			std::string response = res->body;
			logger.Debug("Obtained login response: " + response);

			json r = json::parse(response);

			User tmp = r;

			user = tmp;

			user = tmp;
		}
	}
	catch (std::exception ex) {
		logger.Error("An error occurfed while trying to exewcute.");
	}
}

void Client::CreateUser(std::string username, std::string password, User& user)
{
	LoginForm form;
	form.Username = username;
	form.Password = password;

	json j = form;

	std::string body = j.dump();

	auto res = client.Post("createUser", body.size(),
		[&](size_t offset, size_t length, httplib::DataSink& sink) {
			sink.write(body.data() + offset, length);
			return true;
		},
		"text/plain");

	try {
		if (res != nullptr) {
			std::string response = res->body;

			json r = json::parse(response);

			user = r;
		}
	}
	catch (std::exception ex) {
		logger.Error("An exception occured while trying to parse response.");
	}
}

std::vector<User*> Client::GetUsers(User& user)
{
	json j = user;

	std::string body = j.dump();

	auto res = client.Post("getUsers", body.size(),
		[&](size_t offset, size_t length, httplib::DataSink& sink) {
			sink.write(body.data() + offset, length);
			return true;
		},
		"text/plain");

	try {
		if (res != nullptr) {
			std::string response = res->body;

			json r = json::parse(response);

			std::vector<User*> users = r;

			return users;
		}
	}
	catch (std::exception ex) {
		logger.Error("An exception occured while trying to parse response.");
	}

	return std::vector<User*>();
}
