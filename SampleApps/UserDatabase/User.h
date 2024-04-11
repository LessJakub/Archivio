#pragma once
#include "Entity.h"
#include <string>
#include "AccountType.h"

class User : public Entity
{
public:
	std::string Username;

	std::string Password;

	AccountType Type = UserType;

	User();

	User(const User& user);

	User(std::string Username, std::string Password);
};

