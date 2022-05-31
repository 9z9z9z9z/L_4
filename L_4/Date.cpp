#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include "Date.h"
#include <algorithm>
#include "Storage.h"

using namespace std;

// Work with date on computer
time_t seconds = time(NULL);
tm* timeinfo = localtime(&seconds);

Date::Date(int dayValue, int monthValue, int yearValue)
{
	this->day = dayValue;
	this->month = monthValue;
	this->year = yearValue;
}

Date::Date() :Date(timeinfo->tm_mday, (timeinfo->tm_mon + 1), (timeinfo->tm_year - 100))
{
}

Date::~Date()
{
}

// Get functions
int Date::getDay()
{
	return day;
}
int Date::getMonth()
{
	return month;
}
int Date::getYear()
{
	return year;
}

// Set functions
void Date::setDay(int dayValue) {
	this->day = dayValue;
}
void Date::setMonth(int monthValue) {
	this->month = monthValue;
}
void Date::setYear(int yearValue) {
	this->year = yearValue;
}