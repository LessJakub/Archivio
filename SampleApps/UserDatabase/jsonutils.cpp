#include "jsonutils.h"

void to_json(json& j, const User* u) {

	if (j.empty()) {
		j = json{};
	}

	j["id"] = u->id;
	j["Username"] = u->Username;
	j["Password"] = u->Password;
	j["Type"] = u->Type;
}

void from_json(const json& j, User*& u) {
	if (u == nullptr) {
		u = new User();
	}

	j.at("id").get_to(u->id);
	j.at("Username").get_to(u->Username);
	j.at("Password").get_to(u->Password);
	j.at("Type").get_to(u->Type);
}

void to_json(json& j, const User& u) {

	if (j.empty()) {
		j = json{};
	}

	j["id"] = u.id;
	j["Username"] = u.Username;
	j["Password"] = u.Password;
	j["Type"] = u.Type;
}

void from_json(const json& j, User& u) {

	j.at("id").get_to(u.id);
	j.at("Username").get_to(u.Username);
	j.at("Password").get_to(u.Password);
	j.at("Type").get_to(u.Type);
}

void to_json(json& j, const LoginForm& u)
{
	if (j.empty()) {
		j = json{};
	}

	j["Username"] = u.Username;
	j["Password"] = u.Password;
}

void from_json(const json& j, LoginForm& u)
{
	j.at("Username").get_to(u.Username);
	j.at("Password").get_to(u.Password);
}
