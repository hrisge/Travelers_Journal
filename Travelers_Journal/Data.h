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
	unsigned grade;

	bool correctData = true;

	void convertPhotoListToArrayOfStrings(const char*);
	unsigned numberOfPhotosInList(const char*);
	bool isValidPhoto(const MyString&) const;
public:
	
	void setTimeDep(const CalendarTime&);
	void setTimeDep(unsigned, unsigned, unsigned);
	void setTimeArr(const CalendarTime&);
	void setTimeArr(unsigned, unsigned, unsigned);
	void setPhotos(const ArrayOfStrings&);
	void setPhotosFromList(const char*);
	void setDestination(const MyString&);
	void setDestination(const char*);
	void setComment(const MyString&);
	void setComment(const char*);
	void setGrade(unsigned);

	bool getCorrectData() const;
	const CalendarTime& getTimeArrival() const;
	const CalendarTime& getTimeDeparture() const;
	const ArrayOfStrings& getPhotos() const;
	const MyString& getDestination() const;
	const MyString& getComment() const;
	unsigned getGrade() const;

	void addComment(const MyString&);
	void addPhoto(const MyString&);
};

