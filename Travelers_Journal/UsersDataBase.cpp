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

	for (unsigned i = 0; i < dataBase.getSize(); ++i)
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
unsigned UsersDataBase::getCapacity() const
{
	return capacity;
}
unsigned UsersDataBase::getSize() const
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
void UsersDataBase::deleteData(unsigned n)
{
	delete &dataBase[n];
	for (unsigned i = n; i < getSize(); ++i)
		dataBase[i] = dataBase[i + 1];

	delete &dataBase[getSize()];
	--size;
}

void UsersDataBase::loadData(std::ifstream& inputTripFile)
{
	while (!inputTripFile.eof())
	{
		char buffDestination[MAX_BUFF_SIZE];
		char buffYA[MAX_NUMBER_LEN];
		char buffMA[MAX_NUMBER_LEN];
		char buffDA[MAX_NUMBER_LEN];
		char buffYD[MAX_NUMBER_LEN];
		char buffMD[MAX_NUMBER_LEN];
		char buffDD[MAX_NUMBER_LEN];
		char buffGrade;
		char buffComment[MAX_BUFF3];
		ArrayOfStrings buffImages;

		inputTripFile.getline(buffDestination, MAX_BUFF_SIZE, '$');
		
		inputTripFile.getline(buffYA, MAX_NUMBER_LEN, '-');
		inputTripFile.getline(buffMA, MAX_NUMBER_LEN, '-');
		inputTripFile.getline(buffDA, MAX_NUMBER_LEN, ' ');
		
		inputTripFile.getline(buffYD, MAX_NUMBER_LEN, '-');
		inputTripFile.getline(buffMD, MAX_NUMBER_LEN, '-');
		inputTripFile.getline(buffDD, MAX_NUMBER_LEN, '$');

		inputTripFile.get(buffGrade);
		inputTripFile.getline(buffComment, MAX_BUFF3, '$');
		
		while ((inputTripFile.peek() != '\n') && (!inputTripFile.eof()))
		{
			char buffImage[MAX_BUFF_SIZE];
			inputTripFile.getline(buffImage, MAX_BUFF_SIZE, '#');
			buffImages.addString(buffImage);
		}

		Data buff;
		buff.setDestination(buffDestination);
		buff.setTimeArr(convertCharToInt(buffDA), convertCharToInt(buffMA), convertCharToInt(buffYA));
		buff.setTimeDep(convertCharToInt(buffDD), convertCharToInt(buffMD), convertCharToInt(buffYD));
		buff.setGrade(buffGrade - '0');
		buff.setComment(buffComment);
		buff.setPhotos(buffImages);

		addData(buff);
	}
}

void UsersDataBase::resize()
{
	unsigned newCapacity = getCapacity() * 2;
	if (newCapacity == 0)
		newCapacity = 8;

	Data* newDataBase = new Data[newCapacity];

	for (unsigned i = 0; i < getSize(); ++i)
		newDataBase[i] = getDataBase()[i];

	delete[] dataBase;
	dataBase = newDataBase;
	capacity = newCapacity;
}