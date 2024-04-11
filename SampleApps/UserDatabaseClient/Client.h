#pragma once
#include "../../externallibraries/cpp-httplib-master/httplib.h"
#include "../UserDatabase/User.h"

class Client
{
private:
	httplib::Client client = httplib::Client("localhost", 8080);
public:

	Client();
	~Client();

	void Login(std::string username, std::string password, User& user);

	void CreateUser(std::string username, std::string password, User& user);

	std::vector<User*> GetUsers(User& user);
};

