#pragma once
#include <iostream>
#include "Email.h"
#include "UsersDataBase.h"

class User
{
	Email email;
	UsersDataBase usersDataBase;
	MyString username;
	MyString password;

public:
	User& operator=(const User&);

	const MyString& getPassword() const;
	const MyString& getUsername() const;
	const Email& getEmail() const;
	const UsersDataBase& getUsersDataBase() const;

	void setUsername(const char*);
	void setUsername(const MyString&);
	void setEmail(const Email&);
	void setEmail(const MyString&, const MyString&, const MyString&);
	void setEmail(const char*, const char*, const char*);
	void setPassword(const char*);
	void setPasword(const MyString&);
	
	void addData(const Data&);
	void loadData(std::ifstream&);

	//friend std::istream& operator>>(std::istream&, User&);
	//friend std::ostream& operator<<(std::ostream&, User&);

};

//std::istream& operator>>(std::istream&, User&);
//std::ostream& operator<<(std::ostream&, User&);