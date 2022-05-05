#include "User.h"

void User::free()
{
	delete[] username;
	delete[] password;
}

void User::copyFrom(const User& user)
{
	email = user.getEmail();
	setUsername(user.getUsername());
	setPassword(user.getPassword());
}

const char* User::getPassword() const
{
	return password;
}

void User::setPassword(const char* password)
{
	delete[] this->password;
	this->password = new char[strlen(password) + 1];
	strcpy(this->password, password);
}

User::User() : email()
{
	username = nullptr;
	password = nullptr;
}

User::User(const User& user)
{
	copyFrom(user);
}

User::~User()
{
	free();
}

User& User::operator=(const User& user)
{
	if (this != &user)
	{
		free();
		copyFrom(user);
	}

	return *this;
}

const char* User::getUsername() const
{
	return username;
}

const Email& User::getEmail() const
{
	return email;
}

void User::setUsername(const char* username)
{
	delete[] this->username;
	this->username = new char[strlen(username) + 1];
	strcpy(this->username, username);
}
