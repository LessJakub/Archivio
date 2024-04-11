#include "UserService.h"
#include "../UserDatabase/jsonutils.h"
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

std::vector<User*> UserService::ReadUsersFromFile(std::string path)
{
	try {

		std::fstream f(path);

		json data = json::parse(f);

		std::vector<User*> v = data;

		return v;
	}
	catch (std::exception ex) {

		std::vector<User*> users;

		User* admin = new User("admin", "admin");

		admin->Type = AdminType;

		users.push_back(admin);

		return users;
	}
}

void UserService::SaveUsersToFile(std::string path)
{
	json j = LoadedUsers;

	std::ofstream file(path);

	file << j.dump(4);
}

User& UserService::GetUserById(int id)
{
	for (int i = 0; i < LoadedUsers.size(); i++) {
		if (LoadedUsers[i]->id == id) return *LoadedUsers[i];
	}

	User user;

	return user;
}

User& UserService::Login(LoginForm& form)
{
	User& user = GetUser(form.Username);

	if (user.Password == form.Password) return user;

	User* null = nullptr;

	return *null;
}

User& UserService::CreateUser(std::string username, std::string password, AccountType type)
{
	User* user = new User(username, password);

	user->Type = type;

	LoadedUsers.push_back(user);

	return *user;
}

User& UserService::GetUser(std::string username)
{
	for (int i = 0; i < LoadedUsers.size(); i++) {
		if (LoadedUsers[i]->Username == username) return *LoadedUsers[i];
	}

	User user;

	return user;
}

std::vector<User*> UserService::GetUsers()
{
	return LoadedUsers;
}

User& UserService::UpdateUser(User& user)
{
	User& dbUser = GetUserById(user.id);

	dbUser.Username = user.Username;
	dbUser.Password = user.Password;
	dbUser.Type = user.Type;

	return dbUser;
}

bool UserService::DeleteUser(User& user)
{
	for (auto it = LoadedUsers.begin(); it != LoadedUsers.end(); it++) {
		auto u = *it;

		if (u->id == user.id) {
			LoadedUsers.erase(it);
			return true;
		}
	}

	return false;
}

UserService::UserService()
{
	LoadedUsers = ReadUsersFromFile();
}

UserService::~UserService()
{
	SaveUsersToFile();
}
