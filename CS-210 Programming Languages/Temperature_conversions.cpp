#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

// Function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(int fahrenheit) {
    return (fahrenheit - 32) * 5.0 / 9.0;
}

int main() {
    // Define the names of the input and output files
    const string inputFileName = "FahrenheitTemperature.txt";
    const string outputFileName = "CelsiusTemperature.txt";

    // Create input file stream to read from the input file
    ifstream inputFile(inputFileName);
    // Create output file stream to write to the output file
    ofstream outputFile(outputFileName);

    // Check if the input file opened successfully
    if (!inputFile.is_open()) {
        // Print error message and return with error code if the input file failed to open
        cerr << "Error opening the input file: " << inputFileName << endl;
        return 1;
    }

    // Variables to hold the city name and temperature read from the file
    string city;
    int fahrenheit;

    // Read data from the input file, convert the temperature, and write to the output file
    while (inputFile >> city >> fahrenheit) {
        // Convert Fahrenheit to Celsius
        double celsius = fahrenheitToCelsius(fahrenheit);
        // Write the city name and the converted temperature to the output file
        outputFile << city << " " << fixed << setprecision(2) << celsius << endl;
    }

    // Close the input and output files
    inputFile.close();
    outputFile.close();

    // Print success message
    cout << "Temperature conversion completed successfully." << endl;

    return 0; // Indicate that the program ended successfully
}