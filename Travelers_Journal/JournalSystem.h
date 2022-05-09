#pragma once
#include <fstream>
#include "User.h"

const char usersFile[16] = "usersList.db";
const size_t MAX_BUFF_SIZE = 128;
const size_t MAX_BUFF2 = 8;

class JournalSystem
{
	User* users;
	size_t size;
	size_t capacity;
	size_t loggedIn;
	bool isLoggedIn = false;


	void free();
	void copyFrom(const JournalSystem&);
	void loadUsersData();
	void saveUsersData(size_t);
	void addUserData(std::ifstream&, size_t);
	void resize();

public:
	JournalSystem();
	JournalSystem(const JournalSystem&);
	JournalSystem(JournalSystem&&);
	~JournalSystem();

	const User* getUsers() const;
	size_t getSize() const;
	size_t getCapacity() const;
	size_t getLoggedIn() const;
	bool getIsLoggedIn() const;

	void addUser(const User&);
	void save();
	void addAJourney(const MyString&, const CalendarTime&, const CalendarTime&, size_t, const MyString&, const ArrayOfStrings&);
	void logOut();

	bool checkLogIn(MyString&, MyString&);
	bool checkUser(MyString&);


};

