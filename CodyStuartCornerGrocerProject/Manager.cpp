#include "Manager.h"
#include <string>
#include <iomanip>
#include <algorithm>
#include <cctype>

void Manager::DisplayQueriedItem(string t_product) {
    // Convert the input product string to lowercase
    std::transform(t_product.begin(), t_product.end(), t_product.begin(),
        [](unsigned char c) { return std::tolower(c); });

    // Check if the item exists in the map
    if (m_productMap.find(t_product) != m_productMap.end()) { //the map.find() function returns the last position in a map if it does not find the key, so compare the output of find to the map.end() function if they are not equal than the key was found in the map.
        cout << "The requested produce " << t_product << " was sold " << m_productMap.at(t_product) << " times today." << endl;
    }
    else { //If the key was not found, tell the user
        cout << "The requested produce " << t_product << " was not found." << endl;
    }
}

void Manager::DisplayAllProducts() {
    cout << left << setw(20) << "Product" << "| " << "Frequency" << endl; // Column headers with formatting
    cout << string(30, '-') << endl; // Divider line
    for (const auto& produce : m_productMap) { //Iterates through the private member variable m_productMap to print out the key and frequency in a formatted manner
        cout << left << setw(20) << produce.first << "| " << produce.second << endl; // Align left and set width
    }
}

void Manager::DisplayHistogram() {
    cout << left << setw(20) << "Product" << "| " << "Histogram" << endl; // Column headers
    cout << string(40, '-') << endl; // Divider line
    for (const auto& produce : m_productMap) {
        cout << left << setw(20) << produce.first << "| "; // Align left and set width
        for (int i = 0; i < produce.second; ++i) {
            cout << "*"; // Represent frequency with asterisks
        }
        cout << endl;
    }
}

void Manager::SetMap(map<string, int> t_productMap) {
    m_productMap = t_productMap; //assigns the map passed in to the private member variable map of the Manager class object used to call this function. 
}

map<string, int> Manager::GetMap() {
    return m_productMap; //returns the private member variable map of the Manager class object used to call this function
}

bool Manager::ExitPrompt(bool& t_running) {  //Passed in a bool by reference so it can be modified if the user wishes to exit
    string exitQuery;

    while (true) {
        cout << "Do you wish to exit?\n1. Yes\n2. No\nChoice? [ ]\b\b";
        
        //Using a try/throw/catch block to validate the user entered proper input for the exit function
        try {
            cin >> exitQuery;

            if (exitQuery != "1" && exitQuery != "2") { //This check was hard to figure out, basically if exitQuery evaluates to either a 1 or a 2 the statement becomes true + false, or false + true which in an and equation means false, and when it is false it will not execute the if statement and will not throw an exception
                throw invalid_argument("Invalid input. Please enter 1 or 2.");
            }

            if (exitQuery == "1") { //Sets the bool to false to exit the program if 1 is selected.
                t_running = false;
            }

            break;

        }
        catch (const invalid_argument& e) {
            //handle the invalid input for the exit prompt
            cout << e.what() << endl; //prints the error message
        }
    }

    return t_running;

}