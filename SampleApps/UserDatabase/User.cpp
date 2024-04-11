#include "User.h"
#include "User.h"
#include "User.h"

static int UserIterator = 0;

User::User()
{
}

User::User(const User& user)
{
	if (&user != nullptr) {
		id = user.id;
		Username = user.Username;
		Password = user.Password;
		Type = user.Type;
	}
}

User::User(std::string Username, std::string Password) : Username(Username), Password(Password) {
	id = UserIterator;

	UserIterator += 1;
}

