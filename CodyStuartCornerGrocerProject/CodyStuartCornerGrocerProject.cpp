/* CodyStuartCornerGrocerProject.cpp : This file contains the 'main' function.Program execution begins and ends there.
      Name: Cody Stuart
   Project: Project Three Corner Grocer
      Plan: My plan for completing this assignment is to start by getting all of the functionality working in main first I know this will be somewhat not desired but I'd like for the application to work first and then I will begin updating the program to be clean and stylized.
*/

//Pre-processer section
#include <string>

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

    while (running) {
        cout << "Menu Option One" << endl;
        cout << "Please enter the name of item you want to search for.\nItem: ";

        cin >> userQuery;

        rw.ReadFileData("CS210_Project_Three_Input_File.txt", productMap);

        // Check if the item exists in the map
        if (productMap.find(userQuery) != productMap.end()) {
            cout << "The requested produce " << userQuery << " was sold " << productMap.at(userQuery) << " times today." << endl;
        }
        else {
            cout << "The requested produce " << userQuery << " was not found." << endl;
        }

        cout << "\nMenu Option Two" << endl;

        for (auto produce : productMap) {
            cout << produce.first << ": " << produce.second << endl;
        }

        cout << "\nMenu Option Three" << endl;
        cout << "Histogram of item purchases:" << endl;
        for (const auto& produce : productMap) {
            cout << produce.first << " ";
            for (int i = 0; i < produce.second; ++i) {
                cout << "*"; // Represent frequency with asterisks
            }
            cout << endl;
        }

        cout << "\nMenu Option Four" << endl;
        cout << "Do you wish to exit?\n1. Yes\n2. No\nChoice? [ ]\b\b";

        //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        //getline(cin, exitQuery);
        try {
            cin >> exitQuery;

            if (exitQuery != "1" && exitQuery != "2") {
                throw invalid_argument("Invalid input. Please enter 1 or 2.");
            }

            if (exitQuery == "1") {
                running = false;
            }

        }
        catch (const invalid_argument& e) {
            //handle the invalid input for the exit prompt
            cout << e.what() << endl; //prints the error message
        }

    }

}
