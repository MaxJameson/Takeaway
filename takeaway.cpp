/* ------------------------------------------------------
CMP2801M: Advanced Programming
 *Title      : takeaway
 *Form       : takeaway.cpp
 *Use        : Driver program for "Takeaway" assignment
 *Creator    : Max Jameson & James Brown
 *Student ID : 19702735
------------------------------------------------------ */
#define _CRT_SECURE_NO_WARNINGS

#include "Menu.h"
#include "Order.h"
#include "Item.h"
#include "Appetiser.h"
#include "MainCourse.h"
#include "Beverage.h"
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

bool checkInput(string toCheck)
{
	//Loops through given string
	for (int i = 0; i < toCheck.size(); i++)
	{
		//Checks if the string is a number
		if (isdigit(toCheck[i]) == false)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
}

int main()
{
	//Stores user input
	string userCommand;
	vector <string> parameters;
	string orderConfirm;

	// Create a menu object from a CSV file
	Menu menu = Menu("menu.csv");

	// Create an order object
	Order order = Order();

	while (userCommand != "exit")
	{
		//Takes input from user
		cout << "Enter a command" << endl;
		getline(cin, userCommand);
		char* cstr = new char[userCommand.length() + 1];
		strcpy(cstr, userCommand.c_str());

		cout << "" << endl;
		char* token;
		token = strtok(cstr, " ");

		//Splits input by blank spaces
		while (token != NULL)
		{
			parameters.push_back(token);
			token = strtok(NULL, " ");
		}

		string command = parameters[0];
		

		if (command.compare("menu") == 0)
		{
			//Prints menu
			cout << menu.toString();
		}


		else if (command.compare("add") == 0)
		{

			for (int i = 1; i < parameters.size(); i++)
			{
				string toInt = parameters[i];
				//Checks if the input is valid
				if (checkInput(toInt) == true)
				{
					//Assigns chosen item to object pointer
					Item* choice = menu.getOption(stoi(parameters[i]) - 1);

					//Checks if choice is empty
					if (choice == NULL)
					{
						cout << "This item is not on the menu" << endl;
						cout << "" << endl;
					}

					else
					{
						//Runs method to add item to order
						order.add(choice);
					}

					
				}
				else
				{
					cout << "Ivalid input, please use a menu number when adding to your order" << endl;
					cout << "" << endl;
				}
			}
	
		}

		else if (command.compare("remove") == 0)
		{
			vector<int> removeNums;

			for (int i = 1; i < parameters.size(); i++)
			{
				string toInt = parameters[i];
				//Checks if the input is valid
				if (checkInput(toInt) == true)
				{

					//Checks if choice is empty
					if (i == NULL)
					{
						cout << "This item is not on the menu" << endl;
						cout << "" << endl;
					}

					else
					{
						//Creates vector of inputs
						removeNums.push_back(stoi(parameters[i]) - 1);
						
						
					}

					
				}
				else
				{
					cout << "Ivalid input, please use a menu number when adding to your order" << endl;
					cout << "" << endl;
				}
			}

			//Sorts vector in decending order
			sort(removeNums.begin(), removeNums.end(), greater<int>());

			//Removes inputs from order
			order.remove(removeNums);
			
		}

		else if (command.compare("checkout") == 0)
		{
			//Outputs items on order
			cout << order.toString() << endl;
			cout << "" << endl;
			
			orderConfirm = "";
			cout << "Do you want to place your order?\nType 'y' to confirm or 'n' to go back and modify it." << endl;
			
			//Loops while input is invalid
			while (orderConfirm != "y" && orderConfirm != "n")
			{
				//Gets input from user
				getline(cin, orderConfirm);

				//Checks which input was given
				if (orderConfirm == "y")
				{
					//Sends toString to receipt file
					order.printReceipt();
					order.~Order();
					menu.~Menu();
					cout << "Order placed and receipt printed to 'receipt.txt'" << endl;
					cout << "" << endl;
					userCommand = "exit";

				}
				else if (orderConfirm == "n")
				{

				}
				else
				{
					cout << "Invalid input please try again" << endl;
				}
			}
		}

		else if (command.compare("help") == 0)
		{
			//Displays help information
			cout << "The following are commands this program accepts" << endl;
			cout << "menu - Displays menu" << endl;
			cout << "add [item number from menu] - Adds item selected to order" << endl;
			cout << "remove [item number from menu] - Removes selected item from order" << endl;
			cout << "checkout - Displays items in order with price and savings" << endl;
			cout << "help - Displays list of commands" << endl;
			cout << "exit - Terminates the program "<< endl;
			
		}

		else if(command.compare("exit") == 0)
		{

		}

		else
		{
			cout << "Invalid command, use 'help' for a list of commands";
		}

		parameters.clear();

	}

	cout << "Press any key to quit...";
	std::getchar();

}


