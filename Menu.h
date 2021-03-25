
/* ------------------------------------------------------
CMP2801M: Advanced Programming
 *Title      : takeaway
 *Form       : Menu.h
 *Use        : Header file for Menu class
 *Creator    : Max Jameson
 *Student ID : 19702735
------------------------------------------------------ */
#pragma once
#include "ItemList.h"
#include <vector>
#include <iostream>
#include "item.h"
#include "Appetiser.h"
#include "MainCourse.h"
#include "Beverage.h"


using namespace std;

class Menu: public ItemList
{


public:
	//Class constructor 
	Menu(string menu);

	//Returns object chosen to the program
	Item* getOption(int option);

	//Returns string of the menu
	virtual string toString();


private:

	//Breaks down words in a string into an array
	void breakdown(string vecSplit);

	//Stores current line from csv file
	string itemLine;

	//Stores vector of words from itemLine
	vector<string> tempItem;

	//Creates appetiser objects
	void createApp(vector<string> app);

	//Creates main course objects
	void createMain(vector<string> main);

	//Creates beverage objects
	void createBev(vector<string> bev);
};

