#include "Date.h"
bool Date::updateNeeded = false;

Date::Date()
{
	this->year = 0;
	this->month = 0;
	this->day = 0;
}

Date::Date(int dayIn, int monthIn, int yearIn)
{
	this->day = dayIn;
	this->month = monthIn;
	this->year = yearIn;
}

int Date::getDay()
{
	return this->day;
}

int Date::getMon()
{
	return this->month;
}

int Date::getYear()
{
	return this->year;
}

void Date::setDay(int i)
{
	this->day = i;
}

void Date::setMon(int i)
{
	this->month = i;
}

void Date::setYear(int i)
{
	this->year = i;
}

bool Date::operator<(Date rhs)
{
	if (this->year < rhs.getYear()) {
		return true;
	}
	else if (this->year > rhs.getYear()) {
		return false;
	}
	else {
		if (this->month < rhs.getMon()) {
			return true;
		}
		else if (this->month > rhs.getMon()) {
			return false;
		}
		else {
			if (this->day < rhs.getDay()) {
				return true;
			}
			else if (this->day > rhs.getDay()) {
				return false;
			}
			else {
				return false;
			}
		}
	}
}

bool Date::operator>(Date rhs)
{
	return rhs < *this;
}

bool Date::operator<=(Date rhs)
{
	return !(rhs < *this);
}

bool Date::operator>=(Date rhs)
{
	return !(*this < rhs);
}

bool Date::operator==(Date rhs)
{
	return (this->year == rhs.getYear()) && (this->month == rhs.getMon()) && (this->day == rhs.getDay());
}

bool Date::operator!=(Date rhs)
{
	return (this->year != rhs.getYear()) || (this->month != rhs.getMon()) || (this->day != rhs.getDay());
}

void Date::operator=(Date rhs)
{
	this->year = rhs.getYear();
	this->month = rhs.getMon();
	this->day = rhs.getDay();
}

bool Date::nextDay()
{
	this->day++;

	int months[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int monthsL[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };

	if (year % 4) {
		if (day > months[month - 1]) {
			day = 1;
			month++;
			if (month > 12) {
				year++;
				month = 1;

			}
			Date::updateNeeded = true;
		}
	}
	else {
		if (day > monthsL[month - 1]) {
			day = 1;
			month++;
			if (month > 12) {
				year++;
				month = 1;
			}
			Date::updateNeeded = true;
		}
	}

	if (year > 2017) {

		year = 2017;
		month = 12;
		day = 31;
		Date::updateNeeded = false;
		return false;
	}

	return true;

}

void Date::nextMon()
{
	this->month++;
}

void Date::nextYear()
{
	this->year++;
}

void Date::prevMon()
{
	this->month--;
}

void Date::prevYear()
{
	this->year--;
}

bool Date::isUpdateNeeded()
{
	return updateNeeded;
}

void Date::updated()
{
	Date::updateNeeded = false;
}



Time::Time()
{
	this->hours = 0;
	this->min = 0;
	this->sec = 0;
}

Time::Time(int hourIn, int minIn, int secIn)
{
	this->hours = hourIn;
	this->min = minIn;
	this->sec = secIn;
}

int Time::getHours()
{
	return this->hours;
}

int Time::getMin()
{
	return this->min;
}

float Time::getSec()
{
	return this->sec;
}