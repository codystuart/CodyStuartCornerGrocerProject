#include "ReadWrite.h"
#include <iomanip>
#include <algorithm>
#include <cctype>

void ReadWrite::ReadFileData(string t_fileName, map<string, int>& t_productMap) {

    ifstream fileRead; //Create an ifstream object to use with reading files
    string currProduct; //create a string to hold each object as we read it into our map

    fileRead.open(t_fileName); //Open the file to read

    while (!fileRead.eof()) { //loop until we have reached the end of the file
        fileRead >> currProduct; //read the current line and assign it to our current product string

        // Convert the input product string to lowercase
        std::transform(currProduct.begin(), currProduct.end(), currProduct.begin(),
            [](unsigned char c) { return std::tolower(c); });

        if (t_productMap.count(currProduct) == 0) { //check if the corresponding key to the string exist in the map already map.count(key) returns 0 if a key does not exist
            t_productMap[currProduct] = 1; //assigns new key with value of 1
        }
        else {
            t_productMap.at(currProduct) += 1; //increment pre-existing value to corrosponding key by one 
        }
    }

    fileRead.close(); //Don't forget to close the file when we're done!

    WriteFileData("frequency.dat", t_productMap); //Call this function to backup the frequency data to an outputted file named frequency.dat
}

void ReadWrite::WriteFileData(string t_fileName, map<string, int> t_productMap) {
    ofstream fileWrite; //output file stream object creation

    fileWrite.open(t_fileName, ios_base::app); //Open the file in append mode, I chose append because I wasn't sure if the file should be overwritten with each usage of the program or not. 

    if (fileWrite.is_open()) { //check if the file is open
        fileWrite << left << setw(20) << "Product" << "| " << "Frequency" << endl; // Column headers with formatting
        fileWrite << string(30, '-') << endl; // Divider line
        for (const auto& produce : t_productMap) { // Iterate through the product map to write each product and its frequency to the file
            fileWrite << left << setw(20) << produce.first << "| " << produce.second << endl; // Align left and set width
        }
        fileWrite << endl; //Add a new line to seperate each appending of the frequency info to the file
    }
 
    //Don't forget to close the file when we're done!
    fileWrite.close();
}

int ReadWrite::PromptMenu() {
    int choice; // Stores the user's choice

    //Displays the menu options to the user
    cout << "\nMenu Options:\n";
    cout << "1. Search for an item\n";
    cout << "2. Display all products\n";
    cout << "3. Display histogram\n";
    cout << "4. Exit\n";
    cout << "Please enter your choice: ";

    //loop until a valid choice is entered
    while (true) {
        cin >> choice; //get the user's input

        //Make sure the input is in range
        if (cin.fail() || choice < 1 || choice > 4) {  // Validate input
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the rest of the line
            cout << "Invalid choice. Please enter a number between 1 and 4: "; //prompt for a valid choice after an invalid one
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the rest of the line
            break; // Exit the loop
        }
    }

    return choice; // Return the validated choice
}