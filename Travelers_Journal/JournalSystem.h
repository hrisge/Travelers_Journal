#pragma once
#include <fstream>
#include "User.h"

const char usersFile[16] = "usersList.db";
const unsigned MAX_BUFF_SIZE = 128;
const unsigned MAX_BUFF2 = 8;

class JournalSystem
{
	User* users;
	unsigned size;
	unsigned capacity;
	unsigned loggedIn = 0;
	bool isLoggedIn = false;


	void free();
	void copyFrom(const JournalSystem&);
	void loadUsersData();
	void saveUsersData(unsigned) const;
	void addUserData(std::ifstream&, unsigned);
	void resize();

public:
	JournalSystem();
	JournalSystem(const JournalSystem&);
	JournalSystem(JournalSystem&&);
	~JournalSystem();

	const User* getUsers() const;
	unsigned getSize() const;
	unsigned getCapacity() const;
	unsigned getLoggedIn() const;
	bool getIsLoggedIn() const;

	void addUser(const User&);
	void save() const;
	void addAJourney(const MyString&, const CalendarTime&, const CalendarTime&, unsigned, const MyString&, const ArrayOfStrings&);
	void logOut();

	bool checkLogIn(MyString&, MyString&);
	bool checkUser(MyString&) const;


};

