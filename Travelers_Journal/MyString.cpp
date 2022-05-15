#include <iostream>
#include "MyString.h"


void MyString::free()
{
	delete[] str;
	capacity = 0;
}
void MyString::copyFrom(const MyString& other)
{
	str = new char[other.getStringLen() + 1];
	copyString(other, other.getStringLen()+1);
	capacity = other.getCapacity();
}
void MyString::copyFrom(const char* myString)
{
	capacity = strlen(myString) + 1;
	str = new char[capacity];
	copyString(myString, capacity);
}

void MyString::resize()
{
	unsigned newCapacity = 2 * getCapacity();
	if (newCapacity == 0)
		newCapacity = INITIAL_CAPACITY;

	char* buff = new char[newCapacity];
	for (unsigned i = 0; i < getCapacity(); ++i)
		buff[i] = getString()[i];
	buff[getCapacity()] = '\0';

	delete[] str;
	str = buff;
	capacity = newCapacity;
}

MyString::MyString()
{

}

MyString::MyString(MyString&& myString)
{
	str = myString.str;
	capacity = myString.getCapacity();
	myString.str = nullptr;
	myString.capacity = 0;
}
MyString::MyString(const char* str)
{
	copyFrom(str);
}
MyString::~MyString()
{
	free();
}
MyString::MyString(const MyString& myString)
{
	copyFrom(myString);
}

MyString& MyString::operator=(const MyString& myString)
{
	if (this != &myString)
	{
		if (getString() == nullptr)
			copyFrom(myString);
		else
		{
			free();
			copyFrom(myString);
		}
	}
	return *this;
}
MyString& MyString::operator=(MyString&& myString)
{
	if (this != &myString)
	{
		free();
		str = myString.str;
		capacity = myString.getCapacity();
		myString.str = nullptr;
		myString.capacity = 0;
	}
	return *this;
}
MyString& MyString::operator=(const char* str)
{
	if (getString() != str)
	{
		free();
		copyFrom(str);
	}

	return *this;
}

void MyString::setString(const char* str)
{
	free();
	copyFrom(str);
}
const char* MyString::getString() const
{
	return str;
}
const unsigned MyString::getCapacity() const
{
	return capacity;
}

unsigned MyString::getStringLen() const
{
	if (getString() == nullptr)
		return 0;

	unsigned cnt = 0;
	bool endOfStr = false;
	while (!endOfStr)
	{
		cnt++;
		endOfStr = getString()[cnt] == '\0';
	}
	return cnt;
}
const char MyString::getChar(unsigned k) const
{
	return getString()[k];
}
void MyString::copyString(const MyString& other, unsigned numberOfChars)
{
	while ((numberOfChars >= getCapacity() - 1) || (getCapacity() == 0))
		resize();

	unsigned cnt = numberOfChars - 1;
	for (unsigned i = 0; i < numberOfChars - 1; i++)
		str[i] = other.getString()[i];
	str[cnt] = '\0';
}
void MyString::copyString(const char* str, unsigned numberOfChars)
{
	while ((numberOfChars >= getCapacity() - 1) || (getCapacity() == 0))
		resize();

	unsigned cnt = numberOfChars - 1;
	for (unsigned i = 0; i < numberOfChars - 1; i++)
		this->str[i] = str[i];
	this->str[cnt] = '\0';
}

void MyString::concat(const MyString& myString)
{
	unsigned len1 = getStringLen();
	unsigned len2 = myString.getStringLen() + len1;

	
	while (len1 + len2 > getCapacity())
		resize();

	for (unsigned i = len1; i < len2; ++i)
		str[i] = myString[i - len1];
	str[len2] = '\0';
}
void MyString::concatChar(const char ch)
{
	unsigned len = getStringLen();
	if ((len >= getCapacity() - 1) || (getCapacity() == 0))
		resize();
	str[len] = ch;
	str[len + 1] = '\0';
}

char MyString::operator[](unsigned k) const
{
	return getChar(k);
}

bool MyString::operator==(const MyString& myString) const
{
	unsigned len1 = getStringLen();
	unsigned len2 = myString.getStringLen();

	if (len1 != len2)
		return false;

	for (unsigned i = 0; i < len1; i++)
	{
		if (getChar(i) != myString[i])
			return false;
	}
	return true;
}
bool MyString::operator!=(const MyString& myString) const
{
	return !(*this == myString);
}

std::istream& operator>>(std::istream& ifs, MyString& myString)
{
	myString.free();
	char buff[MAX_BUFF3];
	ifs.getline(buff, MAX_BUFF3);

	myString.copyFrom(buff);
	return ifs;
}
std::ostream& operator<<(std::ostream& ofs, const MyString& myString)
{
	ofs << myString.getString();
	return ofs;
}
