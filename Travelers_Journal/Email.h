#pragma once
#include <iostream>
#include <fstream>
#include "MyString.h"
#pragma warning (disable: 4996)

bool isNameValid(const char*);
bool isNameValid(const MyString&);

class Email
{
	MyString user;
	MyString host;
	MyString adress;

public:
	Email();
	Email(const char*, const char*, const char*);
	Email(const MyString&, const MyString&, const MyString&);

	const MyString& getUser() const;
	const MyString& getHost() const;
	const MyString& getAdress() const;

	void setUser(const char*);
	void setUser(const MyString&);
	void setHost(const char*);
	void setHost(const MyString&);
	void setAdress(const char*);
	void setAdress(const MyString&);

	friend std::istream& operator>>(std::istream&, Email&);
	friend std::ostream& operator<<(std::ostream&, Email&);
};

std::istream& operator>>(std::istream&, Email&);
std::ostream& operator<<(std::ostream&, Email&);