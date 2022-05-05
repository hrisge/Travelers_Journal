#pragma once
#include <iostream>
#include "Email.h"

class User
{
	Email email;
	MyString username;
	MyString password;

	const MyString& getPassword() const;
	void setPassword(const char*);
	void setPasword(const MyString&);

public:

	const MyString& getUsername() const;
	const Email& getEmail() const;

	void setUsername(const char*);
	void setUsername(const MyString&);
	void setEmail(const Email&);
	void setEmail(const MyString&, const MyString&, const MyString&);
	void setEmail(const char*, const char*, const char*);

	//friend std::istream& operator>>(std::istream&, User&);
	//friend std::ostream& operator<<(std::ostream&, User&);

};

//std::istream& operator>>(std::istream&, User&);
//std::ostream& operator<<(std::ostream&, User&);