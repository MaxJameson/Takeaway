/* ------------------------------------------------------
CMP2801M: Advanced Programming
 *Title      : takeaway
 *Form       : MainCourse.cpp
 *Use        : Source file for MainCourse class
 *Creator    : Max Jameson
 *Student ID : 19702735
------------------------------------------------------ */
#include "MainCourse.h"
#include <vector>
#include <iostream>

using namespace std;

	//Class constructor
	MainCourse :: MainCourse(vector<string> itemData)
	{
		//Assigns variables based on objects properties
		itemType = itemData[0];
		name = itemData[1];
		price = itemData[2];
		calories = itemData[3];
	}



