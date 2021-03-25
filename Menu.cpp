/* ------------------------------------------------------
CMP2801M: Advanced Programming
 *Title      : takeaway
 *Form       : Menu.cpp
 *Use        : Source file for Menu class
 *Creator    : Max Jameson
 *Student ID : 19702735
------------------------------------------------------ */
#include "Menu.h"
#include <vector>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;



	//Class contructor
	Menu :: Menu(string menuFile)
	{

		//Opens the menu csv file
		ifstream File;
		File.open(menuFile);

		//Loops through csv file line by line
		while (getline(File, itemLine))
		{
			//clears array to store object elements
			tempItem.clear();

			//Breaks the current line down into a vector for each field
			breakdown(itemLine);

			//Runs method to create appetiser
			if (itemLine[0] == 'a')
			{
				createApp(tempItem);
			}

			//Runs method to create beverage
			else if (itemLine[0] == 'b')
			{
				createBev(tempItem);				
			}

			//Runs method to create Main meal
			else if (itemLine[0] == 'm')
			{
				createMain(tempItem);				
			}
		}

		File.close();
	}

	//Creates appetiser objects
	void Menu :: createApp(vector<string> app)
	{
		//Creates new appetiser and stores a point of it
		Appetiser* p = new Appetiser(app);

		//Adds pointer to itemStore
		items.push_back(p);
	}

	//Creates appetiser objects
	void Menu :: createMain(vector<string> main)
	{
		//Creates new MainCourse and stores a point of it
		MainCourse* p = new MainCourse(main);

		//Adds pointer to itemStore
		items.push_back(p);
	}

	//Creates appetiser objects
	void Menu :: createBev(vector<string> bev)
	{
		//Creates new MainCourse and stores a point of it
		Beverage* p = new Beverage(bev);

		//Adds pointer to itemStore1
		items.push_back(p);
	}

	//Breaks down words in a string into an array
	void Menu :: breakdown(string vecSplit)
	{

		//Stores letter in current word
		string currentWord = "";

		//Loops through string letter buy letter
		for(int i = 0; i <= vecSplit.length(); i++)
		{
			
			//checks if current work has ended
			if (vecSplit[i] == ',' || i == vecSplit.length())
			{
				//Adds new word to vector
				tempItem.push_back(currentWord);

				//Resets variable for new word
				currentWord = "";
			}
			
			else
			{
				//Adds letter to word
				currentWord = currentWord + vecSplit[i];
			}
		}
	}

	//Outputs menu to screen
	string Menu::toString()
	{
		string menuPrint = "";

		menuPrint = menuPrint + "----------Appetisers----------\n";
		int j = 0;

		//Outputs Appetisers
		while ( j < items.size() && items[j]->getType() == "a")
		{

			menuPrint = menuPrint + makeLine(j);

			j++;
		}

		menuPrint = menuPrint + "----------Main dishes----------\n";

		//Outputs Main courses
		while (j < items.size() && items[j]->getType() == "m")
		{

			menuPrint = menuPrint + makeLine(j);

			j++;
		}

		menuPrint = menuPrint + "----------Beverages----------\n";

		//Outputs beverages
		while (j < items.size() && items[j]->getType() == "b")
		{
			

			menuPrint = menuPrint + makeLine(j);

			j++;
		}

		menuPrint = menuPrint + "\n";

		return menuPrint;

	}

	//Returns the user choice the the program
	Item* Menu::getOption(int option)
	{
		//checks if the item is out of the range of the vector
		if (option >= items.size())
		{
			//returns NULL
			return NULL;
		}

		else
		{
			//Returns current object
			Item* ret = items[option];

			//returns object seleted
			return ret;
		}

		
	}


