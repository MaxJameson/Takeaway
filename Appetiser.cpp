/* ------------------------------------------------------
CMP2801M: Advanced Programming
 *Title      : takeaway
 *Form       : Appetiser.cpp
 *Use        : Source code for Appetiser class
 *Creator    : Max Jameson
 *Student ID : 19702735
------------------------------------------------------ */

#include "Appetiser.h"
#include <vector>
#include <iostream>

using namespace std;


	//Class constructor
	Appetiser :: Appetiser(vector<string> itemData)
	{
		//Assigns variables based on objects properties
		itemType = itemData[0];
		name = itemData[1];
		price = itemData[2];
		calories = itemData[3];
		shareable = itemData[4];
		twoForOne = itemData[5];
	}

	//returns string of item details
	string Appetiser::toString()
	{
		//Checks if item is within 2-4-1 or is sharealbe
		if (shareable == "y" && twoForOne == "y")
		{
			return (name + ": $" + price + ", " + calories + " cal " + "(Shareable) " + "(2-4-1)" );
		}
		else if(shareable == "y" && twoForOne != "y")
		{
			return (name + ": $" + price + ", " + calories + " cal " + "(Shareable)");
		}
		else if(shareable != "y" && twoForOne == "y")
		{
			return (name + ": $" + price + ", " + calories + " cal " + "(2-4-1)");
		}
		else
		{
			return (name + ": $" + price + ", " + calories + ", cal");
		}
	}

	//Checks if the item is in the 2-4-1 deal
	bool Appetiser::isTwoForOne()
	{
		if (twoForOne == "y")
		{
			return true;
		}

		else
		{
			return false;
		}
	}
