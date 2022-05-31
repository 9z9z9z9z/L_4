#include "Common.h"

Common::Common()
{
}

Common::Common(string nameValue, double priceValue) {
	this->name = nameValue;
	this->price = priceValue;
	this->count++;
}

Common::~Common() {}

// Get functions
string Common::getName() {
	return this->name;
}
double Common::getPrice() {
	return this->price;
}


// Set functions
void Common::setName(string name) {
	this->name = name;
}
void Common::setPrice(double price) {
	this->price = price;
}

int Common::count = 0;