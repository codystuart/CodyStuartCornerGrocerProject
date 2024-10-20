#include "Manager.h"
#include <string>
#include <iomanip>

void Manager::DisplayQueriedItem(string t_product) {
    // Check if the item exists in the map
    if (m_productMap.find(t_product) != m_productMap.end()) {
        cout << "The requested produce " << t_product << " was sold " << m_productMap.at(t_product) << " times today." << endl;
    }
    else {
        cout << "The requested produce " << t_product << " was not found." << endl;
    }
}

void Manager::DisplayAllProducts() {
    cout << left << setw(20) << "Product" << "| " << "Frequency" << endl; // Column headers
    cout << string(30, '-') << endl; // Divider line
    for (const auto& produce : m_productMap) {
        cout << left << setw(20) << produce.first << "| " << produce.second << endl; // Align left and set width
    }
}

void Manager::DisplayHistogram() {
    //cout << "Histogram of item purchases:" << endl;
    //for (const auto& produce : m_productMap) {
    //    cout << produce.first << " ";
    //    for (int i = 0; i < produce.second; ++i) {
    //        cout << "*"; // Represent frequency with asterisks
    //    }
    //    cout << endl;
    //}

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
    m_productMap = t_productMap;
}

map<string, int> Manager::GetMap() {
    return m_productMap;
}

bool Manager::ExitPrompt(bool& t_running) {
    string exitQuery;

    while (true) {
        cout << "Do you wish to exit?\n1. Yes\n2. No\nChoice? [ ]\b\b";

        //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        //getline(cin, exitQuery);
        try {
            cin >> exitQuery;

            if (exitQuery != "1" && exitQuery != "2") {
                throw invalid_argument("Invalid input. Please enter 1 or 2.");
            }

            if (exitQuery == "1") {
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