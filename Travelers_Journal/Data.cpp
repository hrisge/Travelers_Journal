#include "Data.h"

void Data::convertPhotoListToArrayOfStrings(const char* photosList)
{
	size_t photosListLen = strlen(photosList);
	
	MyString buff;
	for (size_t i = 0; i < photosListLen; ++i)
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

size_t Data::numberOfPhotosInList(const char* photosList)
{
	size_t photoListLen = strlen(photosList);
	size_t res = 0;
	for (size_t i = 0; i < photoListLen; ++i)
		if (photosList[i] == '#')
			res++;
	return res;
}

bool Data::isValidPhoto(const MyString& photo)
{
	bool dot = false;
	size_t len = photo.getStringLen();
	MyString buff;

	for (size_t i = 0; i < len; ++i)
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
void Data::setTimeDep(size_t day, size_t month, size_t year)
{
	CalendarTime buff(day, month, year);
	if (getTimeArrival() <= buff)
		timeDeparture = buff;
}
void Data::setTimeArr(const CalendarTime& time)
{
	timeArival = time;
}
void Data::setTimeArr(size_t day, size_t month, size_t year)
{
	CalendarTime buff(day, month, year);
	if (buff <= getTimeDeparture())
		timeArival = buff;
}

void Data::setPhotos(const ArrayOfStrings& photos)
{
	for (size_t i = 0; i < photos.getSize(); ++i)
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

void Data::setGrade(size_t grade)
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

size_t Data::getGrade() const
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
