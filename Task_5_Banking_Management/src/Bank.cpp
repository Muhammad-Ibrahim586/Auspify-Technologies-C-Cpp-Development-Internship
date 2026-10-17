#include "Bank.h"
#include <iostream>
#include <fstream>
#include <limits>
#include <algorithm>
#include <cctype>

using namespace std;

// Constructor
Bank :: Bank(const string& dataFile)
    : dataFile(dataFile){
    loadAccounts();
}

// Find account by account number
Account* Bank :: findAccountByNumber(int accountNumber){
    for (Account& account : accounts) {
        if (account.getAccountNumber() == accountNumber) {
            return &account;
        }
    }

    return nullptr;
}

// Const version of findAccountByNumber
const Account* Bank :: findAccountByNumber(int accountNumber) const{
    for (const Account& account : accounts) {
        if (account.getAccountNumber() == accountNumber) {
            return &account;
        }
    }

    return nullptr;
}

// Get valid account number
int Bank :: getValidAccountNumber(const string& prompt) const{
    int accountNumber;

    while (true) {
        cout << prompt;

        if (cin >> accountNumber && accountNumber > 0) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return accountNumber;
        }

        cout << " Invalid account number! Please enter a positive number.\n";

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// Get valid monetary amount
double Bank :: getValidAmount(const string& prompt) const{
    double amount;

    while (true) {
        cout << prompt;

        if (cin >> amount && amount > 0) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return amount;
        }

        cout << " Invalid amount! Please enter a positive value.\n";

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// Get non-empty string
string Bank :: getNonEmptyString(const string& prompt) const{
    string value;

    while (true) {
        cout << prompt;
        getline(cin, value);

        if (!value.empty()) {
            return value;
        }

        cout << " Input cannot be empty! Please try again.\n";
    }
}

// Create a new account
void Bank :: createAccount(){
    cout << "\n --- Create Account ---\n";

    int accountNumber = getValidAccountNumber(" Enter account number: ");

    if (findAccountByNumber(accountNumber) != nullptr) {
        cout << " Error: An account with this number already exists!\n";
        return;
    }

    string holderName = getNonEmptyString(" Enter account holder name: ");

    string accountType;

    while (true) {
        cout << " Enter account type (Savings/Current): ";
        getline(cin, accountType);

        if (accountType.empty()) {
            cout << " Account type cannot be empty!\n";
            continue;
        }

        string lowerType = accountType;

        transform(
            lowerType.begin(),
            lowerType.end(),
            lowerType.begin(),
            [](unsigned char c) {
                return static_cast<char>(tolower(c));
            }
        );

        if (lowerType == "savings") {
            accountType = "Savings";
            break;
        }

        if (lowerType == "current") {
            accountType = "Current";
            break;
        }

        cout << " Please enter either Savings or Current!\n";
    }

    double initialDeposit;

    while (true) {
        cout << " Enter initial deposit (0 for none): ";

        if (cin >> initialDeposit && initialDeposit >= 0) {

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            break;
        }

        cout << " Invalid amount! Please enter zero or a positive value.\n";

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    Account account(accountNumber, holderName, accountType);

    accounts.push_back(account);

    if (initialDeposit > 0) {
        accounts.back().deposit(initialDeposit);
    }

    saveAccounts();

    cout << "\n Account created successfully!\n";
}

// Display a specific account
void Bank :: displayAccount() const{
    cout << "\n --- Account Details ---\n";

    int accountNumber = getValidAccountNumber(" Enter account number: ");

    const Account* account = findAccountByNumber(accountNumber);

    if (account == nullptr) {
        cout << " Account with number " << accountNumber << " was not found!\n";

        return;
    }

    cout << "\n ----------------------------------------------\n";
    account->displayDetails();
    cout << " ----------------------------------------------\n";
}

// Deposit money
void Bank :: depositMoney(){
    cout << "\n --- Deposit Money ---\n";

    int accountNumber = getValidAccountNumber(" Enter account number: ");

    Account* account = findAccountByNumber(accountNumber);

    if (account == nullptr) {
        cout << " Account with number " << accountNumber << " was not found!\n";

        return;
    }

    double amount = getValidAmount(" Enter deposit amount: ");

    if (account->deposit(amount)) {
        saveAccounts();

        cout << " Deposit successful!\n";
        cout << " New balance: " << account->getBalance() << endl;
    }
    else {
        cout << " Deposit failed!\n";
    }
}

// Withdraw money
void Bank :: withdrawMoney(){
    cout << "\n --- Withdraw Money ---\n";

    int accountNumber = getValidAccountNumber(" Enter account number: ");

    Account* account = findAccountByNumber(accountNumber);

    if (account == nullptr) {
        cout << " Account with number " << accountNumber << " was not found!\n";

        return;
    }

    double amount = getValidAmount(" Enter withdrawal amount: ");

    if (amount > account->getBalance()) {
        cout << " Transaction rejected: Insufficient balance!\n";

        cout << " Current balance: " << account->getBalance() << endl;

        return;
    }

    if (account->withdraw(amount)) {
        saveAccounts();

        cout << " Withdrawal successful!\n";
        cout << " Remaining balance: " << account->getBalance() << endl;
    }
    else {
        cout << " Withdrawal failed!\n";
    }
}

// Display transaction history
void Bank :: displayTransactionHistory() const{
    cout << "\n --- Transaction History ---\n";

    int accountNumber = getValidAccountNumber(" Enter account number: ");

    const Account* account = findAccountByNumber(accountNumber);

    if (account == nullptr) {
        cout << " Account with number " << accountNumber << " was not found!\n";

        return;
    }

    cout << "\n Account Holder: " << account->getHolderName() << endl;

    account->displayTransactions();
}

// Display all accounts
void Bank :: displayAllAccounts() const{
    cout << "\n --- All Bank Accounts ---\n";

    if (accounts.empty()) {
        cout << " No accounts found!\n";
        return;
    }

    for (const Account& account : accounts) {
        cout << "\n ----------------------------------------------\n";
        account.displayDetails();
    }

    cout << " ----------------------------------------------\n";
}

// Delete an account
void Bank :: deleteAccount(){
    cout << "\n --- Delete Account ---\n";

    int accountNumber = getValidAccountNumber(" Enter account number to delete: ");

    auto it = find_if(
        accounts.begin(),
        accounts.end(),
        [accountNumber](const Account& account) {
            return account.getAccountNumber() == accountNumber;
        }
    );

    if (it == accounts.end()) {
        cout << " Account with number " << accountNumber << " was not found!\n";

        return;
    }

    cout << "\n Account found:\n";
    cout << " ----------------------------------------------\n";
    it->displayDetails();
    cout << " ----------------------------------------------\n";

    char confirmation;

    cout << " Are you sure you want to delete this account? (y/n): ";

    cin >> confirmation;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (confirmation == 'y' || confirmation == 'Y') {

        accounts.erase(it);
        saveAccounts();

        cout << " Account deleted successfully!\n";
    }
    else {
        cout << " Delete operation cancelled!\n";
    }
}

// Save accounts to file
void Bank :: saveAccounts() const{
    ofstream file(dataFile);

    if (!file) {
        cout << " Error: Unable to open data file for writing!\n";
        return;
    }

    for (const Account& account : accounts) {
        file << account.toFileFormat() << '\n';
    }

    file.close();
}

// Load accounts from file
void Bank :: loadAccounts(){
    ifstream file(dataFile);

    if (!file) {
        return;
    }

    string line;

    while (getline(file, line)) {
        if (!line.empty()) {
            try {
                accounts.push_back(Account::fromFileFormat(line));
            }
            catch (const exception&) {
                cout << " Warning: Skipping invalid account record!\n";
            }
        }
    }

    file.close();
}
