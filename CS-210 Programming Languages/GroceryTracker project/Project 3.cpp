#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;

// Define a class for tracking grocery item frequencies
class GroceryTracker {
private:
    map<string, int> itemFrequency; // Map to store item frequencies

public:
    // Constructor to initialize the GroceryTracker object
    GroceryTracker() {
        // Load data from input file and populate itemFrequency map
        loadDataFromFile("CS210_Project_Three_Input_File.txt");
    }

    // Function to load data from input file and populate itemFrequency map
    void loadDataFromFile(const string& filename) {
        ifstream inputFile(filename); // Create an input file stream
        if (!inputFile.is_open()) {
            cerr << "Error: Unable to open input file!" << endl; // Display error message if file cannot be opened
            return;
        }

        string item;
        while (inputFile >> item) { // Read items from the file
            if (itemFrequency.find(item) != itemFrequency.end()) {
                // Increment frequency if item already exists in map
                itemFrequency[item]++;
            }
            else {
                // Add item to map with frequency 1 if it doesn't exist
                itemFrequency[item] = 1;
            }
        }

        inputFile.close(); // Close the input file stream
    }

    // Function to print the frequency of a specific item
    void printItemFrequency(const string& itemName) {
        if (itemFrequency.find(itemName) != itemFrequency.end()) {
            // Print item frequency if item exists in the map
            cout << "Frequency of '" << itemName << "': " << itemFrequency[itemName] << endl;
        }
        else {
            cout << "Item '" << itemName << "' not found!" << endl; // Display message if item not found
        }
    }

    // Function to print the list of items with their frequencies
    void printItemFrequencyList() {
        cout << "Item Frequency List:" << endl;
        for (const auto& pair : itemFrequency) {
            cout << pair.first << " " << pair.second << endl; // Print item and its frequency
        }
    }

    // Function to print the histogram of item frequencies
    void printItemFrequencyHistogram() {
        cout << "Item Frequency Histogram:" << endl;
        for (const auto& pair : itemFrequency) {
            cout << pair.first << " "; // Print item name

            // Print asterisks representing frequency count
            for (int i = 0; i < pair.second; ++i) {
                cout << "*";
            }
            cout << endl;
        }
    }

    // Function to backup item frequency data to a file
    void backupDataToFile(const string& filename) {
        ofstream outputFile(filename); // Create an output file stream
        if (!outputFile.is_open()) {
            cerr << "Error: Unable to open output file!" << endl; // Display error message if file cannot be opened
            return;
        }

        // Write item frequencies to the output file
        for (const auto& pair : itemFrequency) {
            outputFile << pair.first << " " << pair.second << endl;
        }

        outputFile.close(); // Close the output file stream
    }
};

// Main function
int main() {
    GroceryTracker tracker; // Create an instance of GroceryTracker

    // Back up data to frequency.dat
    tracker.backupDataToFile("frequency.dat");

    int choice;
    do {
        // Display menu options
        cout << "Menu Options:" << endl;
        cout << "1. Search for an item" << endl;
        cout << "2. Print item frequency list" << endl;
        cout << "3. Print item frequency histogram" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";

        // Validate input
        while (!(cin >> choice)) {
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            cout << "Invalid input. Please enter a valid option (1-4): ";
        }

        switch (choice) {
        case 1: {
            string searchItem;
            cout << "Enter item to search: ";
            cin.ignore(); // Ignore newline character
            getline(cin, searchItem); // Read input with spaces
            tracker.printItemFrequency(searchItem); // Print frequency of the searched item
            break;
        }
        case 2:
            tracker.printItemFrequencyList(); // Print item frequency list
            break;
        case 3:
            tracker.printItemFrequencyHistogram(); // Print item frequency histogram
            break;
        case 4:
            tracker.backupDataToFile("frequency.dat"); // Backup data to file
            cout << "Data backed up to 'frequency.dat'. Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please enter a valid option (1-4)." << endl;
            break;
        }
    } while (choice != 4); // Continue the loop until the user chooses to exit

    return 0; // Return 0 to indicate successful completion of the program
}
