#pragma once
#include <iostream>
#include <fstream>

const size_t MAX_BUFF_SIZE = 1024;
class MyString
{
	size_t capacity = 0;
	char* str = nullptr;
	

	void free();
	void copyFrom(const MyString&);
	void copyFrom(const char*);
	void resize();

public:
	MyString();
	MyString(const char*);
	MyString(const MyString&);
	MyString(MyString&&);

	~MyString();

	MyString& operator=(const MyString&);
	MyString& operator=(MyString&&);
	MyString& operator=(const char*);

	void setString(const char*);
	const char* getString() const;
	const size_t getCapacity() const;

	size_t getStringLen() const;
	const char getChar(size_t) const;
	void copyString(const MyString&, size_t);
	void copyString(const char*, size_t);

	void concat(const MyString&);
	void concatChar(const char);

	char operator[](size_t) const;
	bool operator==(const MyString&) const;
	bool operator!=(const MyString&) const;

	friend std::istream& operator>>(std::istream&, MyString&);
	friend std::ostream& operator<<(std::ostream&, const MyString&);

};

std::istream& operator>>(std::istream&, MyString&);
std::ostream& operator<<(std::ostream&, const MyString&);