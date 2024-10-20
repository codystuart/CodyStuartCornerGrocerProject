/* CodyStuartCornerGrocerProject.cpp : This file contains the 'main' function.Program execution begins and ends there.
      Name: Cody Stuart
   Project: Project Three Corner Grocer
      Plan: My plan for completing this assignment is to start by getting all of the functionality working in main first I know this will be somewhat not desired but I'd like for the application to work first and then I will begin updating the program to be clean and stylized.
*/

//Pre-processer section
#include "ReadWrite.h"
#include "Manager.h"

//Additonal non-code block statements
using namespace std;

int main() {
    string userQuery;
    string exitQuery;
    bool running = true;
    map<string, int> productMap;
    ReadWrite rw;
    Manager manager;
    int menuChoice;

    //I moved the next two lines out of the loop because it continued to open the file and read the contents into the map artificially increasing the frequency of each item sold.
    rw.ReadFileData("CS210_Project_Three_Input_File.txt", productMap); //Open the file for today's sales and read it into a map
    manager.SetMap(productMap); //use a setter from the manager class to assign the product map to the classes private member variable map

    while (running) { //loop based on a bool set to true, exit the loop (and the program) when the bool is set to false
        menuChoice = rw.PromptMenu();

        switch (menuChoice) {
        case 1:
            cout << "\nItem Query" << endl;
            cout << "---------------------------------" << endl;
            cout << "Please enter the name of item you want to search for.\nItem: ";
            cin >> userQuery;
            manager.DisplayQueriedItem(userQuery);
            break;
        case 2:
            cout << "\nDisplaying All Products Sold" << endl;
            cout << "---------------------------------" << endl;
            manager.DisplayAllProducts();
            break;
        case 3:
            cout << "\Displaying Histogram of Products Sold" << endl;
            cout << "---------------------------------" << endl;
            manager.DisplayHistogram();
            break;
        case 4:
            cout << "\Exit Prompt" << endl;
            cout << "---------------------------------" << endl;
            manager.ExitPrompt(running);
            break;
        }
    }

}
