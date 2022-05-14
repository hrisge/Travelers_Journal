#pragma once
#include <iostream>
#include <fstream>

const unsigned MAX_BUFF3 = 10000;
const unsigned INITIAL_CAPACITY = 4;

class MyString
{
	unsigned capacity = 0;
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

	unsigned getStringLen() const;
	const char getChar(unsigned) const;
	void copyString(const MyString&, unsigned);
	void copyString(const char*, unsigned);

	void concat(const MyString&);
	void concatChar(const char);

	char operator[](unsigned) const;
	bool operator==(const MyString&) const;
	bool operator!=(const MyString&) const;

	friend std::istream& operator>>(std::istream&, MyString&);
	friend std::ostream& operator<<(std::ostream&, const MyString&);

};

std::istream& operator>>(std::istream&, MyString&);
std::ostream& operator<<(std::ostream&, const MyString&);