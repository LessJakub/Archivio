#pragma once
#include "User.h"
#include <nlohmann/json.hpp>
#include "LoginForm.h"

using json = nlohmann::json;

void to_json(json& j, const User* u);

void from_json(const json& j, User*& u);

void to_json(json& j, const User& u);

void from_json(const json& j, User& u);

void to_json(json& j, const LoginForm& u);

void from_json(const json& j, LoginForm& u);