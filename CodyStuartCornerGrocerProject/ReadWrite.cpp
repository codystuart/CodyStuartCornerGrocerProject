#include "ReadWrite.h"

void ReadWrite::ReadFileData(string fileName, map<string, int>& productMap) {

    ifstream fileRead; //Create an ifstream object to use with reading files
    string currProduct; //create a string to hold each object as we read it into our map

    fileRead.open(fileName); //Open the file to read

    while (!fileRead.eof()) { //loop until we have reached the end of the file
        fileRead >> currProduct; //read the current line and assign it to our current product string
        if (productMap.count(currProduct) == 0) { //check if the corresponding key to the string exist in the map already map.count(key) returns 0 if a key does not exist
            productMap[currProduct] = 1; //assigns new key with value of 1
        }
        else {
            productMap.at(currProduct) += 1; //increment pre-existing value to corrosponding key by one 
        }
    }



    fileRead.close(); //Don't forget to close the file when we're done!
}

void ReadWrite::WriteFileData(string fileName, map<string, int> productMap) {
    ofstream fileWrite;

    fileWrite.open(fileName);
    if (fileWrite.is_open()) {
        for (auto produce : productMap) {
            fileWrite << produce.first << ": " << produce.second << endl;
        }
    }
}

int ReadWrite::PromptMenu() {
    int choice;
    cout << "\nMenu Options:\n";
    cout << "1. Search for an item\n";
    cout << "2. Display all products\n";
    cout << "3. Display histogram\n";
    cout << "4. Exit\n";
    cout << "Please enter your choice: ";

    while (true) {
        cin >> choice;

        if (cin.fail() || choice < 1 || choice > 4) {  // Validate input
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the rest of the line
            cout << "Invalid choice. Please enter a number between 1 and 4: ";
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the rest of the line
            break; // Exit the loop
        }
    }

    return choice; // Return the validated choice
}