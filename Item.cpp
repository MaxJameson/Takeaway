/* ------------------------------------------------------
CMP2801M: Advanced Programming
 *Title      : takeaway
 *Form       : Item.cpp
 *Use        : Source file for Item class
 *Creator    : Max Jameson
 *Student ID : 19702735
------------------------------------------------------ */
#include "Item.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

Item::Item()
{

}


//Constructor that creates item
Item:: Item(vector<string> itemData)
{
	//Assigns variables based on objects properties
	itemType = itemData[0];
	name = itemData[1];
	price = itemData[2];
	calories = itemData[3];
}

//returns string of item details
string Item::toString()
{
	return (name + ": $" + price + ", " + calories + " cal");
}

//Returns items type
string Item::getType()
{
	return itemType;
}

//Returns items name
string Item::getName()
{
	return name;
}

//Returns items price
double Item::getPrice()
{
	
	return stod(price);
}