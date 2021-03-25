/* ------------------------------------------------------
CMP2801M: Advanced Programming
 *Title      : takeaway
 *Form       : Item.cpp
 *Use        : Source file for ItemList class
 *Creator    : Max Jameson
 *Student ID : 19702735
------------------------------------------------------ */
#include "ItemList.h"
#include <vector>
#include <iostream>
#include "Item.h"
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

//Returns string to the program
string ItemList::toString()
{
	return "";
}

//Formats item data into a string
string ItemList::makeLine(int itemNum)
{
	return "(" + to_string(itemNum + 1) + ") " + items[itemNum]->toString() + "\n";
}

//Dectructor for ItemList objects
ItemList ::~ItemList()
{
    
    //Loops through itmes in order
    for (int i = 0; i < items.size(); i++)
    {
        //Runs dectructor for Item objects
        items[i]->~Item();
       
    }
}