#pragma once
#include "MyString.h"

const size_t START_CAPACITY = 16;

class UsersDataBase
{
	MyString* dataBase;
	size_t capacity;
	size_t size;

	void free();
	void copyFrom(const UsersDataBase&);

public:
	UsersDataBase();
	UsersDataBase(const UsersDataBase&);
	UsersDataBase(UsersDataBase&&);
	~UsersDataBase();

	UsersDataBase& operator=(const UsersDataBase&);
	UsersDataBase& operator=(UsersDataBase&&);

	const MyString* getDataBase() const;
	size_t getCapacity() const;
	size_t getSize() const;

	void addData(const MyString&);
	void deleteData(size_t);
	
	void resize();
};

