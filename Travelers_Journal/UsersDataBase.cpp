#include "UsersDataBase.h"

void UsersDataBase::free()
{
	delete[] dataBase;
	capacity = 0;
	size = 0;
}
void UsersDataBase::copyFrom(const UsersDataBase& dataBase)
{
	this->dataBase = new Data[dataBase.getCapacity()];
	this->capacity = dataBase.getCapacity();

	for (size_t i = 0; i < dataBase.getSize(); ++i)
	{
		this->dataBase[i] = dataBase.getDataBase()[i];
		++size;
	}
}

UsersDataBase::UsersDataBase()
{
	dataBase = new Data[START_CAPACITY];
	capacity = START_CAPACITY;
	size = 0;
}
UsersDataBase::UsersDataBase(const UsersDataBase& userDataBase)
{
	copyFrom(userDataBase);
}
UsersDataBase::UsersDataBase(UsersDataBase&& userDataBase)
{
	dataBase = userDataBase.dataBase;
	capacity = userDataBase.capacity;
	size = userDataBase.size;

	userDataBase.dataBase = nullptr;
	userDataBase.capacity = 0;
	userDataBase.size = 0;
}
UsersDataBase::~UsersDataBase()
{
	free();
}

UsersDataBase& UsersDataBase::operator=(const UsersDataBase& userDataBase)
{
	if (this != &userDataBase)
	{
		free();
		copyFrom(userDataBase);
	}
	return *this;
}
UsersDataBase& UsersDataBase::operator=(UsersDataBase&& userDataBase)
{
	if (this != &userDataBase)
	{
		dataBase = userDataBase.dataBase;
		capacity = userDataBase.capacity;
		size = userDataBase.size;

		userDataBase.dataBase = nullptr;
		userDataBase.capacity = 0;
		userDataBase.size = 0;
	}
	return *this;
}

const Data* UsersDataBase::getDataBase() const
{
	return dataBase;
}
size_t UsersDataBase::getCapacity() const
{
	return capacity;
}
size_t UsersDataBase::getSize() const
{
	return size;
}

void UsersDataBase::addData(const Data& data)
{
	if (getSize() == getCapacity())
		resize();

	dataBase[getSize()] = data;
	++size;
}
void UsersDataBase::deleteData(size_t n)
{
	delete &dataBase[n];
	for (size_t i = n; i < getSize(); ++i)
		dataBase[i] = dataBase[i + 1];

	delete &dataBase[getSize()];
	--size;
}

void UsersDataBase::resize()
{
	size_t newCapacity = getCapacity() * 2;
	if (newCapacity == 0)
		newCapacity = 8;

	Data* newDataBase = new Data[newCapacity];

	for (size_t i = 0; i < getSize(); ++i)
		newDataBase[i] = getDataBase()[i];

	delete[] dataBase;
	dataBase = newDataBase;
	capacity = newCapacity;
}