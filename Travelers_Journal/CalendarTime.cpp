#include "CalendarTime.h"

CalendarTime::CalendarTime()
{
	setYear(0);
	setMonth(0);
	setDay(0);
}

CalendarTime::CalendarTime(size_t day, size_t month, size_t year)
{
	setYear(year);
	setMonth(month);
	setDay(day);
}

void CalendarTime::setDay(size_t day)
{
	if (day > maxDays[month - 1])
	{
		day = 1;
	}
	this->day = day;
	isModified = true;
	validateDateByChangedCalendars();
}
void CalendarTime::setYear(size_t year)
{
	this->year = year;

	if (isLeapYear())
		maxDays[1] = 29;
	else
		maxDays[1] = 28;
	isModified = true;
	validateDateByChangedCalendars();
}
void CalendarTime::setMonth(size_t month)
{
	if (month > 12)
	{
		month = 1;
	}
	this->month = month;

	if (day > maxDays[month - 1])
		day = maxDays[month - 1];

	isModified = true;
	validateDateByChangedCalendars();
}

size_t CalendarTime::getDay() const
{
	return day;
}
size_t CalendarTime::getMonth() const
{
	return month;
}
size_t CalendarTime::getYear() const
{
	return year;
}

bool CalendarTime::isLeapYear() const
{
	if (year <= 1916)
		return year % 4 == 0;
	return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}

bool CalendarTime::operator<(const CalendarTime& calendarTime) const
{
	if (getYear() > calendarTime.getYear())
		return false;
	else if (getYear() < calendarTime.getYear())
		return true;
	else
	{
		if (getMonth() > calendarTime.getYear())
			return false;
		else if (getMonth() < calendarTime.getMonth())
			return true;
		else
		{
			if (getDay() > calendarTime.getDay())
				return false;
			else
				return true;
		}
	}
}

void CalendarTime::validateDateByChangedCalendars()
{
	if (year == 1916 && month == 4 && day >= 1 && day <= 13)
		day = 15;
}

size_t convertCharToInt(const char* number)
{
	size_t res = 0;
	bool endOfStr = true;
	size_t cnt = 0;

	while (endOfStr)
	{
		res = res * 10 + (number[cnt] - '0');
		endOfStr = !(number[cnt + 1] == '\0');
		cnt++;
	}
	return res;
}

std::istream& operator>>(std::istream& ifs, CalendarTime& calendarTime)
{
	char day[MAX_NUMBER_LEN];
	char month[MAX_NUMBER_LEN];
	char year[MAX_NUMBER_LEN];

	ifs.getline(day, MAX_NUMBER_LEN, '-');
	ifs.getline(month, MAX_NUMBER_LEN, '-');
	ifs.getline(year, MAX_NUMBER_LEN, '\n');

	calendarTime.setYear(convertCharToInt(year));
	calendarTime.setMonth(convertCharToInt(month));
	calendarTime.setDay(convertCharToInt(day));

	return ifs;
}

std::ostream& operator<<(std::ostream& ofs, const CalendarTime& calendarTime)
{
	ofs << calendarTime.getDay() << '-' << calendarTime.getMonth() << '-' << calendarTime.getYear();
	return ofs;
}
