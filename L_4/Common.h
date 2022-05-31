#pragma once

#include <iostream>

using namespace std;

class Common
{
protected:
	string name;
	double price;
public:
	static int count;

	Common();
	Common(string nameValue, double priceValue);
	~Common();

	// Get functions
	string getName();
	double getPrice();

	// Set functions
	void setName(string name);
	void setPrice(double price);
};
