#pragma once
#include "../UserDatabase/User.h"
#include "../UserDatabase/LoginForm.h"
#include <vector>

#define DEFAULT_FILE_PATH "users.json"

class UserService
{
private:
	std::vector<User*> ReadUsersFromFile(std::string path = DEFAULT_FILE_PATH);

	void SaveUsersToFile(std::string path = DEFAULT_FILE_PATH);

protected:
	std::vector<User*> LoadedUsers;

	User& GetUserById(int id);

public:

	User& Login(LoginForm& form);

	User& CreateUser(std::string username, std::string password, AccountType type);

	User& GetUser(std::string username);

	std::vector<User*> GetUsers();

	User& UpdateUser(User& user);

	bool DeleteUser(User& user);

	UserService();

	~UserService();
};

