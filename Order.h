/* ------------------------------------------------------
CMP2801M: Advanced Programming
 *Title      : takeaway
 *Form       : Order.h
 *Use        : Header file for Order class
 *Creator    : Max Jameson
 *Student ID : 19702735
------------------------------------------------------ */
#pragma once
#include <vector>
#include <iostream>
#include "ItemList.h"
#include "item.h"
#include "Appetiser.h"
#include "MainCourse.h"
#include "Beverage.h"

using namespace std;


class Order : ItemList
{

public:
	//Adds item to order
	void add(Item* option);

	//Removes item from order
	void remove(vector<int> RemoveNums);

	//Sends order to a text file
	void printReceipt();

	//Returns order to program
	virtual string toString();

private:

	//Stores savings value
	double savings = 0;

	//Stores total value
	double total = 0;

	//Calculates total cost of order
	void calculateTotal();

};

