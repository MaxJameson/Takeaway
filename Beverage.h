/* ------------------------------------------------------
CMP2801M: Advanced Programming
 *Title      : takeaway
 *Form       : Beverage.h
 *Use        : Header file for Beverage class
 *Creator    : Max Jameson
 *Student ID : 19702735
------------------------------------------------------ */


#pragma once
#include "Item.h"
#include <vector>
#include <iostream>

using namespace std;

class Beverage : public Item
{

public:
	//Class constructor
	Beverage(vector<string> itemData);

	//Checks if the item in alcoholic
	bool isAlcoholic();

	//returns string of beverage details
	virtual string toString();

private:

	//Stores drinks volume
	string volume;

	//Stores alcoholic content 
	string abv;


};

