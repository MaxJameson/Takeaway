/* ------------------------------------------------------
CMP2801M: Advanced Programming
 *Title      : takeaway
 *Form       : Order.cpp
 *Use        : Source file for Order class
 *Creator    : Max Jameson
 *Student ID : 19702735
------------------------------------------------------ */
#include "Order.h"
#include "Menu.h"
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>


using namespace std;

//Adds item to order
 void Order::add(Item* option)
{
     //Adds item to vector of items
     items.push_back(option);
     total = total + option->getPrice();

     //Checks if the item in an alchoholic drink
     if (option->getType() == "b" && dynamic_cast<Beverage*>(option)->isAlcoholic() == true)
     {
         
         cout << "ID will need to be proved when receiving alcoholic items" << endl;

     }
     cout << (option->getName() + " was added to order") << endl;
     cout << "" << endl;
}


 //Removes item from order
 void Order::remove(vector<int> RemoveNums)
 {
   
    for (int i = 0; i < RemoveNums.size(); i++)
    {
        //checks if the item is out of the range of the vector
        if (RemoveNums[i] < items.size())
        {
            //Deletes item
            cout << (items[RemoveNums[i]]->getName() + " was removed from the order") << endl;
            cout << "" << endl;
            items.erase(items.begin() + RemoveNums[i]);


        }
        else
        {
            cout << "This item is not on your order(" << RemoveNums[i] + 1 << "), only items on an order can be removed" << endl;
            cout << "" << endl;
        }
    }

    

    //Recalculates total
    total = 0;
    for (int i = 0; i < items.size(); i++)
    {
        total = total + items[i]->getPrice();
    }

 }

 //Calculates total cost of order
 void Order::calculateTotal()
 {
     //Resets savings
     savings = 0;

     //Creates vector to store price value
     vector <double> twoFOneSavings;

     //Loops through list of items
     for (int i = 0; i < items.size(); i++)
     {
         //Checks if item is an appetiser and checks if it qualifies for 2-4-1
         if (items[i]->getType() == "a" && dynamic_cast<Appetiser*>(items[i])->isTwoForOne() == true)
         {
             twoFOneSavings.push_back(items[i]->getPrice());
         }
     }

     //Sorts vector in decending order
     sort(twoFOneSavings.begin(), twoFOneSavings.end(), greater<int>());

     //Stores the start point to loop through the vector
     int startpoint = 0;

     //Stores the length of the list
     int len = twoFOneSavings.size();

     //Checks if the length of the list is even
     if (twoFOneSavings.size() % 2 !=0)
     {

         len++;
     }
    
     //Sets start point for the 
     startpoint = (len / 2);

     //Adds up the two for one discount
     for (int i = startpoint; i < twoFOneSavings.size(); i++)
     {
         savings = savings + twoFOneSavings[i];
     }
 }


 string Order::toString()
 {
     
    //stores string to return
    string orderString = "";
    
    //Stores total with saving applied
    double dicountTotal = 0;

     //Checks if order is empty
     if (items.empty())
     {
         cout << "This order is empty, please add items to process an order" << endl;
         cout << "" << endl;
     }

     else
     {
         orderString = "===========Checkout===========\n";   

         //Loops through itmes in order
         for (int j = 0; j < items.size(); j++)
         {
             
             
             //Adds current item to oder
             orderString = orderString + makeLine(j);
         }
     }

     //Calculates total savings 
     calculateTotal();




     //Calculates disounted total
     dicountTotal = total - savings;

     //converts floats using string stream
     stringstream disStream;
     stringstream savStream;

     disStream << dicountTotal;
     savStream << savings;

     string disString = disStream.str();
     string savString = savStream.str();

     
     orderString = orderString + "----------\n";

     //Checks if any savings have been made
     if (savings == 0)
     {
         orderString = orderString + "Savings: $" + savString + "\n";
     }
     else
     {
         orderString = orderString + "2-4-1 discount applied! Savings: $" + savString + "\n";
     }
       
     //Outputs total
     orderString = orderString + "Total: $" + disString + "\n";
     orderString = orderString + "";


     return orderString;
 }


 void Order::printReceipt()
 {
     //Creates receipt.txt file
     ofstream receiept("receipt.txt");

     //Stores output from toString
     receiept << toString();
     receiept.close();
 }   