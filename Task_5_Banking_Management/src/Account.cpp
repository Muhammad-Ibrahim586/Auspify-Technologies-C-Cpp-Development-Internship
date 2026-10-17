#include "Account.h"
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

// Default constructor
Account :: Account()
    : accountNumber(0), holderName(""), accountType(""), balance(0.0) {}

// Parameterized constructor
Account :: Account(int accountNumber, string holderName, string accountType, double balance)
    : accountNumber(accountNumber), holderName(holderName), accountType(accountType), balance(balance) {}

// Getter functions
int Account :: getAccountNumber() const{
    return accountNumber;
}

string Account :: getHolderName() const{
    return holderName;
}

string Account :: getAccountType() const{
    return accountType;
}

double Account :: getBalance() const{
    return balance;
}

// Deposit money
bool Account :: deposit(double amount){
    if (amount <= 0) {
        return false;
    }

    balance += amount;

    transactions.push_back({" Deposit", amount, balance});

    return true;
}

// Withdraw money
bool Account :: withdraw(double amount){
    if (amount <= 0) {
        return false;
    }

    if (amount > balance) {
        return false;
    }

    balance -= amount;

    transactions.push_back({" Withdrawal", amount, balance});

    return true;
}

// Display account details
void Account :: displayDetails() const{
    cout << " Account Number: " << accountNumber;
    cout << " | Holder Name: " << holderName << endl;
    cout << " Account Type: " << accountType;
    cout << " | Balance: " << fixed << setprecision(2) << balance << endl;
}

// Display transaction history
void Account :: displayTransactions() const{
    cout << "\n --- Transaction History ---\n";

    if (transactions.empty()) {
        cout << " No transactions found!\n";
        return;
    }

    cout << left << setw(15) << " Type" << setw(15) << "Amount" << setw(15) << "Balance" << endl;

    cout << " ---------------------------------------------------\n";

    for (const Transaction& transaction : transactions) {
        cout << left << setw(15) << transaction.type << setw(15) << fixed << setprecision(2) << transaction.amount << setw(15) << transaction.balanceAfter << endl;
    }
}

// Convert account data to file format
string Account :: toFileFormat() const{
    ostringstream output;

    output << accountNumber << "|" << holderName << "|" << accountType << "|" << fixed << setprecision(2) << balance;

    for (const Transaction& transaction : transactions) {
        output << "|" << transaction.type << "," << fixed << setprecision(2) << transaction.amount << "," << transaction.balanceAfter;
    }

    return output.str();
}

// Create Account from a saved file line
Account Account :: fromFileFormat(const string& line){
    stringstream input(line);

    string accountNumberString;
    string holderName;
    string accountType;
    string balanceString;

    getline(input, accountNumberString, '|');
    getline(input, holderName, '|');
    getline(input, accountType, '|');
    getline(input, balanceString, '|');

    int accountNumber = stoi(accountNumberString);
    double balance = stod(balanceString);

    Account account(accountNumber, holderName, accountType, balance);

    string transactionData;

    while (getline(input, transactionData, '|')) {
        stringstream transactionStream(transactionData);

        string type;
        string amountString;
        string balanceAfterString;

        getline(transactionStream, type, ',');
        getline(transactionStream, amountString, ',');
        getline(transactionStream, balanceAfterString, ',');

        if (!type.empty() && !amountString.empty() && !balanceAfterString.empty()) {

            Transaction transaction;

            transaction.type = type;
            transaction.amount = stod(amountString);
            transaction.balanceAfter = stod(balanceAfterString);

            account.transactions.push_back(transaction);
        }
    }

    return account;
}
