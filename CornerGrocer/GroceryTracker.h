
#pragma once

#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

class GroceryTracker {
private:
    // Stores grocery items and their purchase counts.
    map<string, int> itemFrequencies;

public:
    // Reads grocery purchases from a text file.
    void LoadItems(const string& filename);

    // Saves purchase frequencies to a backup file.
    void SaveBackup(const string& filename);

    // Searches for a specific grocery item.
    void SearchItem();

    // Displays all grocery items and their frequencies.
    void DisplayFrequencies();

    // Displays a histogram of item frequencies.
    void DisplayHistogram();
};
#pragma once
