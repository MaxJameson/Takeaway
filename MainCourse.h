/* ------------------------------------------------------
CMP2801M: Advanced Programming
 *Title      : takeaway
 *Form       : MainCourse.h
 *Use        : Header file for MainCourse class
 *Creator    : Max Jameson
 *Student ID : 19702735
------------------------------------------------------ */

#pragma once
#include "Item.h"
#include <vector>
#include <iostream>

using namespace std;

class MainCourse : public Item
{
public:

	//Class constructor
	MainCourse(vector<string> itemData);
	
	
};

