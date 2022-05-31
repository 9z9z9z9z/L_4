#include "Stock.h" 

Stock::Stock()
{
}
Stock::Stock(string nameValue, double priceValue, int quantValue, int numValue, Date dateValue)
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

Stock::~Stock()
{
}

// Get functions
int Stock::getNum() {
	return this->num;
}
int Stock::getQuant() {
	return this->quant;
}
Date Stock::getDate()
{
	return this->date;
}

// Set functions
void Stock::setNum(int numValue) {
	this->num = numValue;
}
void Stock::setQuant(int quantValue) {
	this->quant = quantValue;
}

int Stock::count = 0;