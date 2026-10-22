
#include "GroceryTracker.h"

// Reads the grocery purchases and counts each item.
void GroceryTracker::LoadItems(const string& filename) {
    ifstream inputFile(filename);
    string item;

    // Clears previous data before loading the file.
    itemFrequencies.clear();

    if (!inputFile.is_open()) {
        cout << "Error: Could not open " << filename << endl;
        return;
    }

    // Counts each occurrence of a grocery item.
    while (inputFile >> item) {
        itemFrequencies[item]++;
    }

    inputFile.close();
}

// Creates a backup file containing purchase frequencies.
void GroceryTracker::SaveBackup(const string& filename) {
    ofstream outputFile(filename);

    if (!outputFile.is_open()) {
        cout << "Error: Could not create backup file." << endl;
        return;
    }

    for (const auto& item : itemFrequencies) {
        outputFile << item.first << " " << item.second << endl;
    }

    outputFile.close();
}

// Searches for a specific grocery item.
void GroceryTracker::SearchItem() {
    string item;

    cout << "\nEnter the item you want to search for: ";
    cin >> item;

    auto foundItem = itemFrequencies.find(item);

    if (foundItem != itemFrequencies.end()) {
        cout << item << " was purchased "
            << foundItem->second << " times." << endl;
    }
    else {
        cout << item << " was purchased 0 times." << endl;
    }
}

// Displays all grocery items and their frequencies.
void GroceryTracker::DisplayFrequencies() {
    cout << "\nGrocery Item Frequencies\n";
    cout << "------------------------\n";

    for (const auto& item : itemFrequencies) {
        cout << item.first << " " << item.second << endl;
    }
}

// Displays a histogram using asterisks.
void GroceryTracker::DisplayHistogram() {
    cout << "\nGrocery Purchase Histogram\n";
    cout << "--------------------------\n";

    for (const auto& item : itemFrequencies) {
        cout << item.first << " ";

        // Prints one asterisk for each purchase.
        for (int i = 0; i < item.second; i++) {
            cout << "*";
        }

        cout << endl;
    }
}
