#include "Storage.h"

Storage::Storage()
{
}

Storage::Storage(string nameValue, double priceValue, int quantValue, int numValue, Date dateValue)
{
	this->name = nameValue;
	this->price = priceValue;
	this->quant = quantValue;
	this->num = numValue;
	this->date.setDay(dateValue.getDay());
	this->date.setMonth(dateValue.getMonth());
	this->date.setYear(dateValue.getYear());
	this->count++;
}

Storage::~Storage() {}

// Get functions
int Storage::getQuant()
{
	return this->quant;
}
int Storage::getNum()
{
	return this->num;
}
Date Storage::getDate()
{
	return this->date;
}

// Set functions
void Storage::setQuant(int quantValue)
{
	this->quant = quantValue;
}
void Storage::setNum(int numValue)
{
	this->num = numValue;
}

int Storage::count = 0;