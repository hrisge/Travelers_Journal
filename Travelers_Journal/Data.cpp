#include "Data.h"

bool Data::isValidPhotos(const MyString&)
{
	return false;
}

void Data::setTime(const CalendarTime& time)
{
	this->time = time;
}

void Data::setTime(size_t day, size_t month, size_t year)
{
	time.setYear(year);
	time.setMonth(month);
	time.setDay(day);
}

void Data::setPhotos(const ArrayOfStrings& photos)
{
	for (size_t i = 0; i < photos.getSize(); ++i)
		if (isValidPhotos(photos.getArray()[i]))
			this->photos.addString(photos.getArray()[i]);
}

void Data::setDestination(const MyString& destination)
{
	this->destination = destination;
}

void Data::setDestination(const char* destination)
{
	this->destination = destination;
}

void Data::setComment(const MyString& comment)
{
	this->comment = comment;
}

void Data::setComment(const char* comments)
{
	this->comment = comment;
}

void Data::setGrade(size_t grade)
{
	if (grade > 1 && grade < 6)
		this->grade = grade;
	else
		this->grade = 0;
}
