#pragma once
#include "../../ExternalLibraries/cpp-httplib-master/httplib.h"
#include "UserService.h"
#include <string>

class UsersController
{
private:
	httplib::Server server;

	UserService userService;

public:

	void StartListen(std::string host, int port);

	UsersController();

	~UsersController();
};

