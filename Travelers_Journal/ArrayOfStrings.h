#pragma once
#include "MyString.h"

const unsigned BASE_SIZE = 4;

class ArrayOfStrings
{
	unsigned capacity = 0;
	unsigned size = 0;
	MyString* array = nullptr;
	
	void free();
	void copyFrom(const ArrayOfStrings&);

	void resize();

public:
	ArrayOfStrings();
	ArrayOfStrings(const ArrayOfStrings&);
	ArrayOfStrings(ArrayOfStrings&&);
	~ArrayOfStrings();

	ArrayOfStrings& operator=(const ArrayOfStrings&);
	ArrayOfStrings& operator=(ArrayOfStrings&&);

	const MyString& operator[](unsigned) const;

	const MyString* getArray() const;
	unsigned getCapacity() const;
	unsigned getSize() const;

	void addString(const MyString&);
};

