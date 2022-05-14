#include "Data.h"

void Data::convertPhotoListToArrayOfStrings(const char* photosList)
{
	unsigned photosListLen = strlen(photosList);
	
	MyString buff;
	for (unsigned i = 0; i < photosListLen; ++i)
	{
		if (photosList[i] == '#')
		{
			photos.addString(buff);
			buff = "";
			continue;
		}
		buff.concatChar(photosList[i]);
	}
	photos.addString(buff);
}
unsigned Data::numberOfPhotosInList(const char* photosList)
{
	unsigned photoListLen = strlen(photosList);
	unsigned res = 0;
	for (unsigned i = 0; i < photoListLen; ++i)
		if (photosList[i] == '#')
			res++;
	return res;
}
bool Data::isValidPhoto(const MyString& photo) const
{
	bool dot = false;
	unsigned len = photo.getStringLen();
	MyString buff;

	for (unsigned i = 0; i < len; ++i)
	{
		if (photo[i] == '.')
			dot = true;
		else if (dot)
			buff.concatChar(photo.getChar(i));
	}
	return (buff == "jpeg") || (buff == "png");
}

void Data::setTimeDep(const CalendarTime& time)
{
	if (getTimeArrival() <= time)
		timeDeparture = time;
}
void Data::setTimeDep(unsigned day, unsigned month, unsigned year)
{
	CalendarTime buff(day, month, year);
	if (getTimeArrival() <= buff)
		timeDeparture = buff;
}
void Data::setTimeArr(const CalendarTime& time)
{
	timeArival = time;
}
void Data::setTimeArr(unsigned day, unsigned month, unsigned year)
{
	CalendarTime buff(day, month, year);
	if (buff <= getTimeDeparture())
		timeArival = buff;
}
void Data::setPhotos(const ArrayOfStrings& photos)
{
	for (unsigned i = 0; i < photos.getSize(); ++i)
		if (isValidPhoto(photos.getArray()[i]))
			this->photos.addString(photos.getArray()[i]);
}
void Data::setPhotosFromList(const char* photosList)
{
	convertPhotoListToArrayOfStrings(photosList);
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
void Data::setGrade(unsigned grade)
{
	if (grade > 1 && grade < 6)
		this->grade = grade;
	else
		this->grade = 0;
}

const CalendarTime& Data::getTimeArrival() const
{
	return timeArival;
}
const CalendarTime& Data::getTimeDeparture() const
{
	return timeDeparture;
}
const ArrayOfStrings& Data::getPhotos() const
{
	return photos;
}
const MyString& Data::getDestination() const
{
	return destination;
}
const MyString& Data::getComment() const
{
	return comment;
}
unsigned Data::getGrade() const
{
	return grade;
}

void Data::addComment(const MyString& comment)
{
	this->comment.concat(comment);
}
void Data::addPhoto(const MyString& photo)
{
	if (isValidPhoto(photo))
		photos.addString(photo);
}
