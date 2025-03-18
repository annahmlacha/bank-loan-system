#include <iostream>
#include <string>
using namespace std;

class Loan {
private:
    string borrowerName;
    double loanAmount;
    double interestRate;
    int loanTerm;  // Loan term in years
    double totalAmountToRepay;
