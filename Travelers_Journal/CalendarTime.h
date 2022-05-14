#pragma once
#include <iostream>
#include <fstream>

const unsigned NUMBER_OF_MONTHS = 12;
const unsigned MAX_NUMBER_LEN = 8;

size_t convertCharToInt(const char*);

class CalendarTime
{
	unsigned day;
	unsigned month;
	unsigned year;

	unsigned maxDays[NUMBER_OF_MONTHS] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	bool isModified = true;

	void validateDateByChangedCalendars();

public:
	CalendarTime();
	CalendarTime(unsigned, unsigned, unsigned);

	void setDay(unsigned);
	void setYear(unsigned);
	void setMonth(unsigned);

	unsigned getDay() const;
	unsigned getMonth() const;
	unsigned getYear() const;

	bool isLeapYear() const;
	
	bool operator<=(const CalendarTime&) const;

	friend std::istream& operator>>(std::istream&, CalendarTime&);
	friend std::ostream& operator<<(std::ostream&, const CalendarTime&);
};

std::istream& operator>>(std::istream&, CalendarTime&);
std::ostream& operator<<(std::ostream&, const CalendarTime&);