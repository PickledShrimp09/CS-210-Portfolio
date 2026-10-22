
/*
 * Name: Andrew Bryan
 * Course: CS 210 - Programming Languages
 * Assignment: Project Three - Corner Grocer
 * Date: October 13, 2026
 *
 * Description:
 * This program tracks grocery purchases using data from a text file.
 * Users can search for individual items, view purchase frequencies,
 * and display a histogram of the results. The program also creates
 * a backup file named frequency.dat to store the purchase data.
 */

#include <iostream>
#include <limits>
#include "GroceryTracker.h"

using namespace std;

int main() {
    GroceryTracker tracker;
    int menuChoice = 0;

    // Loads grocery purchases from the input file.
    tracker.LoadItems("CS210_Project_Three_Input_File.txt");

    // Automatically creates the required backup file.
    tracker.SaveBackup("frequency.dat");

    // Keeps the program running until the user exits.
    while (menuChoice != 4) {
        cout << "\n================================\n";
        cout << "       CORNER GROCER MENU\n";
        cout << "================================\n";
        cout << "1. Search for a grocery item\n";
        cout << "2. Display item frequencies\n";
        cout << "3. Display frequency histogram\n";
        cout << "4. Exit program\n";
        cout << "================================\n";
        cout << "Enter your selection: ";

        // Validates menu input.
        if (!(cin >> menuChoice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "\nInvalid input. Please enter a number from 1 to 4.\n";
            continue;
        }

        switch (menuChoice) {
        case 1:
            // Searches for a specific item.
            tracker.SearchItem();
            break;

        case 2:
            // Displays all item frequencies.
            tracker.DisplayFrequencies();
            break;

        case 3:
            // Displays the purchase histogram.
            tracker.DisplayHistogram();
            break;

        case 4:
            // Exits the program.
            cout << "\nThank you for using Corner Grocer!\n";
            break;

        default:
            cout << "\nInvalid selection. Please choose 1 through 4.\n";
            break;
        }
    }

    return 0;
}
