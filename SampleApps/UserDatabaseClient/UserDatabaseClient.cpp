#include <iostream>
#include <string>
#include "../../externallibraries/cpp-httplib-master/httplib.h"
#include "Client.h"
#include "../UserDatabase/User.h"
#include <functional>
#include <vector>
#include "utils.h"

bool finished = false;

Client client;

User user;

void displayToConsole(std::string message) {
	std::cout << message << "\n";
}

template<class T>
T getUserInput(std::string message = "") {
	std::cout << message;
	T x;
	std::cin >> x;

	//std::cout << "\n";
	return x;
}

void finish() {
	finished = true;
}

void Login() {
	displayToConsole("Enter login credentials");
	std::string username = getUserInput<std::string>("Enter username: ");
	std::string password = getUserInput<std::string>("Enter password: ");

	logger.Info("User trying to login: " + username);

	client.Login(username, password, user);

	if (&user != nullptr) {
		logger.Info("Successful login as: " + user.Username);
	}
	else {
		logger.Warning("User failed to log in");
	}
}

void Logout() {
	user.Username = "";
}

void CreateUser() {
	std::string username = getUserInput<std::string>("Enter username for the new user: ");
	std::string password = getUserInput<std::string>("Enter password for the new user: ");
	logger.Info("Creating user: " + username);

	client.CreateUser(username, password, user);
}

void ListUsers() {
	logger.Info("Listing users");

	std::vector<User*> users = client.GetUsers(user);

	for (int i = 0; i < users.size(); i++) {
		User* user = users[i];
		if (user == nullptr) continue;
		displayToConsole(std::to_string(i) + ". " + user->Username);
	}
	displayToConsole("--- ---");

}

void DisplayUserCredentials() {
	logger.Info("Displaying credentials");

	displayToConsole("Username: " + user.Username);
	displayToConsole("Password: " + user.Password);
}

void LogOnServer() {
	std::string data = getUserInput<std::string>("Enter: ");
	logger.Info(data);
}

int main()
{
	//logger.Info("Started client application");

    displayToConsole("Welcome to test http application");

	std::vector<std::pair<std::string, std::function<void()>>> functions;

	functions.push_back({ "Log on server", LogOnServer });
	functions.push_back({ "List users", ListUsers });
	functions.push_back({ "Create user", CreateUser });
	functions.push_back({ "Display user credentials", DisplayUserCredentials });
	functions.push_back({ "Change user", Login });
	functions.push_back({ "Logout", Logout });
	functions.push_back({ "Exit", finish });


	while (!finished) 
	{
		while (user.Username == "")
		{
			Login();

			if (user.Username == "") {
				logger.Error("An error occured during login");

				displayToConsole("An error occured while logging in");
				displayToConsole("Please try again");
			}
		}

		for (int i = 0; i < functions.size(); i++) {
			std::string message = std::to_string(i + 1) + ". " + functions[i].first;
			displayToConsole(message);
		}

		int selected = -1;

		do {
			selected = getUserInput<int>("Select function You want to call:");
			selected -= 1;
		} while (!(selected >= 0 && selected < functions.size()));

		std::function<void()> func = functions[selected].second;

		try {
			func();
		}
		catch (std::exception ex) {
			logger.Error("An error occurfed while trying to exewcute: " + functions[selected].first + ". Error: " + ex.what());
		}
	}
}
