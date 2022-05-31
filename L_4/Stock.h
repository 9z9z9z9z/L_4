#pragma once

#include "Date.h"
#include "Common.h"

class Stock : public Common
{
private:
	int num;
	int quant;
	Date date;
public:
	static int count;

	Stock();
	Stock(string nameValue, double priceValue, int quantValue, int numValue, Date dateValue);
	~Stock();

	// Get functions
	int getNum();
	int getQuant();
	Date getDate();

	// Set functions
	void setNum(int numValue);
	void setQuant(int quantValue);


	friend bool operator>(Stock*& a, Date& b);
};