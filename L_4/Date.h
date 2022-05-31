#pragma once


class Date
{
private:
	int day;
	int month;
	int year;
public:

	Date();
	Date(int dayValue, int monthValue, int yearValue);
	~Date();

	// Get functions
	int getDay();
	int getMonth();
	int getYear();

	// Set functions
	void setDay(int dayValue);
	void setMonth(int monthValue);
	void setYear(int yearValue);

	// Functions
	Date operator=(Date data);
};