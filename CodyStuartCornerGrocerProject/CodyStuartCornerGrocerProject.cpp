/* CodyStuartCornerGrocerProject.cpp : This file contains the 'main' function.Program execution begins and ends there.
      Name: Cody Stuart
   Project: Project Three Corner Grocer
      Plan: 
*/

//Pre-processer section
#include "ReadWrite.h"
#include "Manager.h"

//Additonal non-code block statements
using namespace std;

int main() {
    bool running = true; //loop variable for programs main functionality
    string userQuery; //Variable to hold the produce item the user is searching for
    map<string, int> productMap; //Map to use with file reading and pass in to our Manager class map setter
    ReadWrite rw; //ReadWrite class object to use its functions
    Manager manager; //Manager class object to use its functions
    int menuChoice; //Holds the integer equal to the menu selection of the user

    //I moved the next two lines out of the loop because it continued to open the file and read the contents into the map artificially increasing the frequency of each item sold.
    rw.ReadFileData("CS210_Project_Three_Input_File.txt", productMap); //Open the file for today's sales and read it into a map
    manager.SetMap(productMap); //use a setter from the manager class to assign the product map to the classes private member variable map

    while (running) { //loop based on a bool set to true, exit the loop (and the program) when the bool is set to false
        menuChoice = rw.PromptMenu(); //calls PromptMenu function from ReadWrite class and assigns the return value to menuChoice

        switch (menuChoice) { //Handle user's menu choice
        case 1:
            cout << "\nItem Query" << endl; //Indicate the start of an item query
            cout << "---------------------------------" << endl; //line break for better visuals
            cout << "Please enter the name of item you want to search for.\nItem: ";
            cin >> userQuery;
            manager.DisplayQueriedItem(userQuery);
            break;
        case 2:
            cout << "\nDisplaying All Products Sold" << endl; //Indicates displaying all products
            cout << "---------------------------------" << endl; //line break for better visuals
            manager.DisplayAllProducts();
            break;
        case 3:
            cout << "\Displaying Histogram of Products Sold" << endl; //Indicates displaying Histogram
            cout << "---------------------------------" << endl; //line break for better visuals
            manager.DisplayHistogram();
            break;
        case 4:
            cout << "\Exit Prompt" << endl; //Indicates exit prompt
            cout << "---------------------------------" << endl; //line break for better visuals
            rw.ExitPrompt(running);
            break;
        }
    }

}
