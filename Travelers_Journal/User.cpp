#include "User.h"

User& User::operator=(const User& user)
{
	if (this != &user)
	{
		email = user.getEmail();
		usersDataBase = user.getUsersDataBase();
		username = user.getUsername();
		password = user.getPassword();
	}
	return *this;
}

const MyString& User::getPassword() const
{
	return password;
}
void User::setPassword(const char* password)
{
	this->password = password;
}
void User::setPasword(const MyString& password)
{
	this->password = password;
}


const MyString& User::getUsername() const
{
	return username;
}
const Email& User::getEmail() const
{
	return email;
}

const UsersDataBase& User::getUsersDataBase() const
{
	return usersDataBase;
}

void User::setUsername(const char* username)
{
	if (isNameValid(username))
		this->username = username;
	else
		std::cout << "Username does not contain the proper symbols! \n";
}
void User::setUsername(const MyString& username)
{
	if (isNameValid(username))
		this->username = username;
	else
		std::cout << "Username does not contain the proper symbols! \n";
}

void User::setEmail(const Email& email)
{
	this->email = email;
}
void User::setEmail(const MyString& user, const MyString& host, const MyString& adress)
{
	email.setUser(user);
	email.setHost(host);
	email.setAdress(adress);
}
void User::setEmail(const char* user, const char* host, const char* adress)
{
	email.setUser(user);
	email.setHost(host);
	email.setAdress(adress);
}

void User::addData(const Data& data)
{
	usersDataBase.addData(data);
}

void User::loadData(std::ifstream& inputTripFile)
{
	usersDataBase.loadData(inputTripFile);
}

