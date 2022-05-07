#pragma once
#include "MyString.h"

const size_t BASE_SIZE = 4;

class ArrayOfStrings
{
	size_t capacity = 0;
	size_t size = 0;
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

	const MyString* getArray() const;
	size_t getCapacity() const;
	size_t getSize() const;

	void addString(const MyString&);
};

