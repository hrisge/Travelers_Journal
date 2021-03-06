#include "ArrayOfStrings.h"

void ArrayOfStrings::free()
{
	delete[] array;
	size = 0;
	capacity = 0;
}
void ArrayOfStrings::copyFrom(const ArrayOfStrings& arr)
{
	array = new MyString[arr.getCapacity()];
	for (unsigned i = 0; i < arr.getSize(); i++)
		array[i] = arr.getArray()[i];
	size = arr.getSize();
	capacity = arr.getCapacity();
}

void ArrayOfStrings::resize()
{
	capacity *= 2;
	if (getCapacity() == 0)
		capacity = BASE_SIZE;

	MyString* buff = new MyString[getCapacity()];
	for (unsigned i = 0; i < getSize(); ++i)
		buff[i] = getArray()[i];

	delete[] array;
	array = buff;
}

ArrayOfStrings::ArrayOfStrings()
{

}
ArrayOfStrings::ArrayOfStrings(const ArrayOfStrings& arr)
{
	copyFrom(arr);
}
ArrayOfStrings::ArrayOfStrings(ArrayOfStrings&& arr)
{
	array = arr.array;
	size = arr.size;
	capacity = arr.capacity;

	arr.array = nullptr;
	arr.size = 0;
	arr.capacity = 0;
}
ArrayOfStrings::~ArrayOfStrings()
{
	free();
}

ArrayOfStrings& ArrayOfStrings::operator=(const ArrayOfStrings& arr)
{
	if (this != &arr)
	{
		free();
		copyFrom(arr);
	}
	return *this;
}
ArrayOfStrings& ArrayOfStrings::operator=(ArrayOfStrings&& arr)
{
	if (this != &arr)
	{
		free();
		array = arr.array;
		size = arr.size;
		capacity = arr.capacity;

		arr.array = nullptr;
		arr.size = 0;
		arr.capacity = 0;
	}
	return *this;
}

const MyString& ArrayOfStrings::operator[](unsigned i) const
{
	return getArray()[i];
}

const MyString* ArrayOfStrings::getArray() const
{
	return array;
}

unsigned ArrayOfStrings::getCapacity() const
{
	return capacity;
}

unsigned ArrayOfStrings::getSize() const
{
	return size;
}

void ArrayOfStrings::addString(const MyString& str)
{
	while ((getCapacity() == 0) || (getCapacity() == getSize()))
		resize();

	array[getSize()] = str;
	++size;
}
