#pragma once
#include <iostream>
#include <string>
#include "Date.h"
#include "Common.h"

using namespace std;

class Storage :public Common
{
private:
	int quant;
	int num;
	Date date;
public:
	static int count;

	Storage();
	Storage(string nameValue, double priceValue, int quantValue, int numValue, Date dateValue);
	~Storage();

	// Get functions
	int getQuant();
	int getNum();
	Date getDate();

	// Set functions
	void setQuant(int quantValue);
	void setNum(int numValue);

	// Functions
	friend void sortQuant(Storage*& database);

	Storage operator=(Storage data);
};
