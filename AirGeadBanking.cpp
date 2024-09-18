//Mason Williams CS-210

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Function to print a specified number of characters
void printChar(int numChar, char n) {
    for (int i = 0; i < numChar; ++i) {
        cout << n;
    }
    cout << endl;
}

// Class definition for Investment
class Investment {
private:
    double initialInvestment;
    double monthlyDeposit;
    double annualInterest;
    int numYears;

public:
    // Constructor to initialize member variables
    Investment() : initialInvestment(0), monthlyDeposit(0), annualInterest(0), numYears(0) {}

    // Setter methods for member variables
    void setInitialInvestment(double amount) {
        initialInvestment = amount;
    }

    void setMonthlyDeposit(double amount) {
        monthlyDeposit = amount;
    }

    void setAnnualInterest(double rate) {
        annualInterest = rate;
    }

    void setNumYears(int years) {
        numYears = years;
    }

    // Method to calculate interest
    double calculateInterest(double openingAmount, double deposit) {
        return (openingAmount + deposit) * (annualInterest / 100.0 / 12.0);
    }

    // Method to print investment details for a year
    void printDetails(int year, double yearEndBalance, double interestEarned) {
        // Print the year, year-end balance, and interest earned with two tabs between each field
        // and dollars printed to the second decimal place
        cout << year << "\t\t$" << fixed << setprecision(2) << setw(10) << yearEndBalance
            << "\t\t$" << fixed << setprecision(2) << setw(10) << interestEarned << endl;
    }

    // Method to generate report without additional monthly deposits
    void generateReportWithoutDeposits() {
        double openingAmount = initialInvestment;
        char n = '-'; // Character for printing dashes
        double totalInterest = 0;

        // Print the header for the report
        cout << "\nBalance and Interest Without Additional Monthly Deposits\n";
        printChar(75, n);  // Print dashes using the function
        printChar(75, n);
        cout << "Year\t\tYear End Balance\t\tYear End Earned Interest\n";
        printChar(75, n);  // Print dashes using the function

        // Loop through each year to calculate and print details
        for (int year = 1; year <= numYears; ++year) {
            double yearlyInterest = 0;
            // Loop through each month to calculate interest
            for (int month = 1; month <= 12; ++month) {
                double interest = calculateInterest(openingAmount, 0);
                openingAmount += interest;
                yearlyInterest += interest;
            }
            totalInterest += yearlyInterest;
            // Print details for the year
            printDetails(year, openingAmount, yearlyInterest);
        }
    }

    // Method to generate report with additional monthly deposits
    void generateReportWithDeposits() {
        double openingAmount = initialInvestment;
        char n = '-'; // Character for printing dashes
        double totalInterest = 0;

        // Print the header for the report
        cout << "\nBalance and Interest With Additional Monthly Deposits\n";
        printChar(75, n);  // Print dashes using the function
        printChar(75, n);
        cout << "Year\t\tYear End Balance\t\tYear End Earned Interest\n";
        printChar(75, n);  // Print dashes using the function

        // Loop through each year to calculate and print details
        for (int year = 1; year <= numYears; ++year) {
            double yearlyInterest = 0;
            // Loop through each month to calculate interest
            for (int month = 1; month <= 12; ++month) {
                double interest = calculateInterest(openingAmount, monthlyDeposit);
                openingAmount += monthlyDeposit + interest;
                yearlyInterest += interest;
            }
            totalInterest += yearlyInterest;
            // Print details for the year
            printDetails(year, openingAmount, yearlyInterest);
        }
    }
};

// Main function
int main() {
    Investment* invest = new Investment(); // Create an instance of Investment using a pointer
    double initialInvestment, monthlyDeposit, annualInterest;
    int numYears;
    char choice = 'y';
    char n = '*'; // Character for printing stars

    // Main loop for input and report generation
    while (choice == 'y' || choice == 'Y') {
        // Display the input menu
        printChar(40, n); // Print stars using the function
        cout << "************ Data Input ****************" << endl;
        cout << "Initial Investment Amount: ";
        cin >> initialInvestment;
        invest->setInitialInvestment(initialInvestment);

        cout << "Monthly Deposit: ";
        cin >> monthlyDeposit;
        invest->setMonthlyDeposit(monthlyDeposit);

        cout << "Annual Interest: ";
        cin >> annualInterest;
        invest->setAnnualInterest(annualInterest);

        cout << "Number of Years: ";
        cin >> numYears;
        invest->setNumYears(numYears);

        cout << "Press any key to continue. . .";
        cin.ignore();
        cin.get();

        // Display the input values before continuing
        printChar(40, n); // Print stars using the function
        cout << "************ Data Input ****************" << endl;
        cout << "Initial Investment Amount: $" << fixed << setprecision(2) << initialInvestment << endl;
        cout << "Monthly Deposit: $" << fixed << setprecision(2) << monthlyDeposit << endl;
        cout << "Annual Interest: " << fixed << setprecision(2) << annualInterest << "%" << endl;
        cout << "Number of Years: " << numYears << endl;
        printChar(40, n); // Print stars using the function

        // Generate the reports
        invest->generateReportWithoutDeposits();
        invest->generateReportWithDeposits();

        cout << "Do you want to test different values? (y/n): ";
        cin >> choice;
        cout << "\n";
    }

    delete invest; // Free memory before exiting

    return 0;
}
