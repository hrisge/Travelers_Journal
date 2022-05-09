#pragma once
#include <fstream>
#include "User.h"

const char usersFile[16] = "usersList.db";
const size_t MAX_BUFF_SIZE = 128;
const size_t MAX_BUFF2 = 8;
const size_t MAX_BUFF3 = 10000;

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




};

