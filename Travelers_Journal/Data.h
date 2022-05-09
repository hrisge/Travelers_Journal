#pragma once
#include "CalendarTime.h"
#include "MyString.h"
#include "ArrayOfStrings.h"

class Data
{
	CalendarTime timeArival = {0, 0, 0};
	CalendarTime timeDeparture = {0, 0, 0};
	ArrayOfStrings photos;
	MyString destination;
	MyString comment;
	size_t grade;

	void convertPhotoListToArrayOfStrings(const char*);
	size_t numberOfPhotosInList(const char*);
	bool isValidPhoto(const MyString&);
public:
	
	void setTimeDep(const CalendarTime&);
	void setTimeDep(size_t, size_t, size_t);
	void setTimeArr(const CalendarTime&);
	void setTimeArr(size_t, size_t, size_t);
	void setPhotos(const ArrayOfStrings&);
	void setPhotosFromList(const char*);
	void setDestination(const MyString&);
	void setDestination(const char*);
	void setComment(const MyString&);
	void setComment(const char*);
	void setGrade(size_t);

	const CalendarTime& getTimeArrival() const;
	const CalendarTime& getTimeDeparture() const;
	const ArrayOfStrings& getPhotos() const;
	const MyString& getDestination() const;
	const MyString& getComment() const;
	size_t getGrade() const;

	void addComment(const MyString&);
	void addPhoto(const MyString&);
};

