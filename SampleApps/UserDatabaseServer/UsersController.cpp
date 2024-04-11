#include "UsersController.h"
#include <nlohmann/json.hpp>
#include "../UserDatabase/LoginForm.h"
#include "../UserDatabase/jsonutils.h"
#include <ArchivioHeader.h>
#include <Logger.h>

using json = nlohmann::json;

Logger logger;

void UsersController::StartListen(std::string host, int port)
{
	logger.Info("starting listening: " + host + ":" + std::to_string(port));
	server.listen(host, port);
}

UsersController::UsersController()
{
	logger.Info("Creating controller");

	server.Post("login", [&](const httplib::Request& req, httplib::Response& res) {
		logger.Info("--- Login ---");
		json data = json::parse(req.body);

		LoginForm form = data;

		User& user = userService.Login(form);

		if (&user != nullptr) {
			logger.Info("User " + user.Username + " logged in");

			json userResponse = user;

			res.body = userResponse.dump();
		}
		else {
			logger.Info("User " + form.Username + " not found");

		}
		logger.Info("--- End Login ---");
	});

	server.Post("createUser", [&](const httplib::Request& req, httplib::Response& res) {
		logger.Info("--- createUser ---");

		json data = json::parse(req.body);

		LoginForm form = data;

		User& user = userService.CreateUser(form.Username, form.Password, UserType);

		json userResponse = &user;

		res.body = userResponse.dump();

		logger.Info("--- End createUser ---");
	});

	server.Post("getUsers", [&](const httplib::Request& req, httplib::Response& res) {
		logger.Info("--- getUsers ---");

		json data = json::parse(req.body);

		User user = data;

		if (user.Type == AdminType) {
			logger.Info("User authorized");

			std::vector<User*> users = userService.GetUsers();

			json userResponse = users;

			res.body = userResponse.dump();
		}
		else {
			logger.Info("User not authorized to getUsers");
		}
		logger.Info("--- End getUsers ---");

		});
}

UsersController::~UsersController()
{
}
