/* ------------------------------------------------------
CMP2801M: Advanced Programming
 *Title      : takeaway
 *Form       : Appetiser.h
 *Use        : Header file for Appetiser class
 *Creator    : Max Jameson
 *Student ID : 19702735
------------------------------------------------------ */


#pragma once
#include "Item.h"
#include <vector>
#include <iostream>

using namespace std;

class Appetiser :public Item
{

public:
	//Class constructor
	Appetiser(vector<string> itemData);

	//Checks if the item is in the 2-4-1 deal
	bool isTwoForOne();

	//returns string of appetiser details
	virtual string toString();

private:

	//Stores if the item is shareable
	string shareable;

	//Store if the item is two for one
	string twoForOne;

};

