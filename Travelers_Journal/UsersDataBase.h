#pragma once
#include "Data.h"

const size_t START_CAPACITY = 16;

class UsersDataBase
{
	Data* dataBase;
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

	const Data* getDataBase() const;
	size_t getCapacity() const;
	size_t getSize() const;

	void addData(const Data&);
	void deleteData(size_t);
	
	void resize();
};

