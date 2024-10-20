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

    while (running) { //loop based on a bool set to true, exit the loop (and the program) when the bool is set to false
        rw.ReadFileData("CS210_Project_Three_Input_File.txt", productMap); //Open the file for today's sales and read it into a map
        
        manager.SetMap(productMap); //use a setter from the manager class to assign the product map to the classes private member variable map

        menuChoice = rw.PromptMenu();

        switch (menuChoice) {
        case 1:
            cout << "\nMenu Option One" << endl;
            cout << "Please enter the name of item you want to search for.\nItem: ";
            cin >> userQuery;
            manager.DisplayQueriedItem(userQuery);
            break;
        case 2:
            cout << "\nMenu Option Two" << endl;

            manager.DisplayAllProducts();
            break;
        case 3:
            cout << "\nMenu Option Three" << endl;

            manager.DisplayHistogram();
            break;
        case 4:
            cout << "\nMenu Option Four" << endl;

            manager.ExitPrompt(running);
            break;
        }
    }

}
