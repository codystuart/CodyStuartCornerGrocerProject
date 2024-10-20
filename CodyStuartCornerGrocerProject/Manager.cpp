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
    cout << string(33, '-') << endl; // Divider line
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
