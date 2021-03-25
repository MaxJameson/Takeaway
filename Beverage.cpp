/* ------------------------------------------------------
CMP2801M: Advanced Programming
 *Title      : takeaway
 *Form       : Beverage.cpp
 *Use        : source file for Beverage class
 *Creator    : Max Jameson
 *Student ID : 19702735
------------------------------------------------------ */

#include "Beverage.h"
#include <vector>
#include <iostream>

using namespace std;

	
	
	//Class constructor
	Beverage :: Beverage(vector<string> itemData)
	{
		//Assigns variables based on objects properties
		itemType = itemData[0];
		name = itemData[1];
		price = itemData[2];
		calories = itemData[3];
		volume = itemData[6];
		abv = itemData[7];
	}

	//returns string of item details
	string Beverage::toString()
	{
		//Checks if item is alcoholic
		if (abv != "0")
		{
			return (name + ": $" + price + ", " + calories + " cal (" + volume + "ml, " + abv + "% abv)");
		}
		
		else
		{
			return (name + ": $" + price + ", " + calories + ", cal (" + volume + "ml)");
		}
	}

	bool Beverage::isAlcoholic()
	{
		//Checks if the item contains alcohol
		if (abv != "0")
		{
			return true;
		}
		else
		{
			return false;
		}
	}



