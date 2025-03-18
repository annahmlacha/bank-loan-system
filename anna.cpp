
    #include <iostream>
#include <cmath> // For pow() function

using namespace std;

class Loan {
private:
    double loanAmount;
    double interestRate;
    int loanTerm; // in years

public:
    // Constructor to initialize the loan details
    Loan(double amount, double rate, int term) {
        loanAmount = amount;
        interestRate = rate;
        loanTerm = term;
    }

    // Function to calculate the monthly payment
    double calculateMonthlyPayment() {
        double monthlyRate = interestRate / 100 / 12; // Monthly interest rate
        int totalPayments = loanTerm * 12; // Total number of payments (months)
        
        // Using the formula for monthly payment calculation
        double monthlyPayment = (loanAmount * monthlyRate) /
                                (1 - pow(1 + monthlyRate, -totalPayments));
        return monthlyPayment;
    }

    // Function to calculate total amount paid over the loan period
    double calculateTotalAmountPaid() {
        double monthlyPayment = calculateMonthlyPayment();
        return monthlyPayment * loanTerm * 12; // Total amount paid over the entire loan period
    }

    // Function to display loan details
    void displayLoanDetails() {
        double monthlyPayment = calculateMonthlyPayment();
        double totalAmountPaid = calculateTotalAmountPaid();

        cout << "Loan Details:" << endl;
        cout << "Loan Amount: $" << loanAmount << endl;
        cout << "Interest Rate: " << interestRate << "%" << endl;
        cout << "Loan Term: " << loanTerm << " years" << endl;
        cout << "Monthly Payment: $" << monthlyPayment << endl;
        cout << "Total Amount Paid: $" << totalAmountPaid << endl;
    }
};

int main() {
    double amount, rate;
    int term;

    // Taking user input
    cout << "Enter loan amount: $";
    cin >> amount;
    
    cout << "Enter interest rate (in %): ";
    cin >> rate;
    
    cout << "Enter loan term (in years): ";
    cin >> term;

    // Create Loan object and display details
    Loan loan(amount, rate, term);
    loan.displayLoanDetails();

    return 0;
}
