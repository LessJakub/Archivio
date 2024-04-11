#include "LoginForm.h"

LoginForm::LoginForm()
{
}

LoginForm::~LoginForm()
{

}

LoginForm::LoginForm(const LoginForm& form) : Username(form.Username), Password(form.Password) {

}

LoginForm::LoginForm(LoginForm& form) : Username(form.Username), Password(form.Password) {

}

LoginForm::LoginForm(std::string username, std::string password) : Username(username), Password(password) {

}
