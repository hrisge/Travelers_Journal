#pragma once
#include "CalendarTime.h"
#include "MyString.h"
#include "ArrayOfStrings.h"

class Data
{
	CalendarTime time;
	ArrayOfStrings photos;
	MyString destination;
	MyString comment;
	size_t grade;

	bool isValidPhotos(const MyString&);
public:
	
	void setTime(const CalendarTime&);
	void setTime(size_t, size_t, size_t);
	void setPhotos(const ArrayOfStrings&);
	void setDestination(const MyString&);
	void setDestination(const char*);
	void setComment(const MyString&);
	void setComment(const char*);
	void setGrade(size_t);
};

