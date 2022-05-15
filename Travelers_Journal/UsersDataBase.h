#pragma once
#include "Data.h"

const unsigned START_CAPACITY = 16;
const unsigned MAX_BUFF_SIZE = 128;

class UsersDataBase
{
	Data* dataBase;
	unsigned capacity;
	unsigned size;

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
	unsigned getCapacity() const;
	unsigned getSize() const;

	void addData(const Data&);
	void deleteData(unsigned);
	void loadData(std::ifstream&);
	
	void resize();
};

