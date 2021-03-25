/* ------------------------------------------------------
CMP2801M: Advanced Programming
 *Title      : takeaway
 *Form       : Item.h
 *Use        : Header file for Item class
 *Creator    : Max Jameson
 *Student ID : 19702735
------------------------------------------------------ */

#pragma once
#include <vector>
#include <iostream>

using namespace std;

class Item
{
public:
	//Constructor that creates item
	Item(vector<string> itemData);

	//Returns items type
	string getType();

	//Returns items price
	double getPrice();

	//Returns items name
	string getName();

	//returns string of item details
	virtual string toString();

	protected:
		
		Item ();

		//Stores Item type
		string itemType;

		//Stores item name
		string name;

		//Stores price of iem
		string price;

		//Stores Items calories
		string calories;

		



		

		
		

};

