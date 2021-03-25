/* ------------------------------------------------------
CMP2801M: Advanced Programming
 *Title      : takeaway
 *Form       : ItemList.h
 *Use        : Source file for ItemList class
 *Creator    : Max Jameson
 *Student ID : 19702735
------------------------------------------------------ */
#pragma once
#include <vector>
#include "Item.h"

using namespace std;

class ItemList
{
	protected:

		//Vector to store item object pointers
		vector<Item*> items;

		//Virtual method to return a string to the program
		virtual string toString();

		//Formats item data to string
		string makeLine(int itemNum);

		//Dectructor for ItemList objects
		~ItemList();

};

