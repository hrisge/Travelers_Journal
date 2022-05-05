#pragma once
#include <iostream>
#include "Email.h"

class User
{
	Email email;
	MyString username;
	MyString password;

	const char* getPassword() const;
	void setPassword(const char*);

public:

	const char* getUsername() const;
	const Email& getEmail() const;

	void setUsername(const char*);


};

