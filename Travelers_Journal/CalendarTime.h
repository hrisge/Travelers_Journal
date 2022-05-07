#pragma once
#include <iostream>
#include <fstream>

const size_t NUMBER_OF_MONTHS = 12;
const size_t MAX_NUMBER_LEN = 8;

size_t convertCharToInt(const char*);

class CalendarTime
{
	size_t day;
	size_t month;
	size_t year;

	size_t maxDays[NUMBER_OF_MONTHS] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	bool isModified = true;

	void validateDateByChangedCalendars();

public:
	CalendarTime();
	CalendarTime(size_t, size_t, size_t);

	void setDay(size_t);
	void setYear(size_t);
	void setMonth(size_t);

	size_t getDay() const;
	size_t getMonth() const;
	size_t getYear() const;

	bool isLeapYear() const;
	
	bool operator<(const CalendarTime&) const;

	friend std::istream& operator>>(std::istream&, CalendarTime&);
	friend std::ostream& operator<<(std::ostream&, const CalendarTime&);
};

std::istream& operator>>(std::istream&, CalendarTime&);
std::ostream& operator<<(std::ostream&, const CalendarTime&);