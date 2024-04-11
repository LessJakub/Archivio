#pragma once
#include <string>

class LoginForm
{
public:

	std::string Username;

	std::string Password;

	LoginForm();
	~LoginForm();

	LoginForm(const LoginForm& form);

	LoginForm(LoginForm& form);

	LoginForm(std::string username, std::string password);

};

