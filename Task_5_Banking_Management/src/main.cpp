#include "Bank.h"
#include <iostream>
#include <limits>

using namespace std;

void displayMenu(){
    cout << "\n ========================================\n";
    cout << "         BANKING MANAGEMENT SYSTEM\n";
    cout << " ========================================\n";
    cout << "  1. Create Account\n";
    cout << "  2. Display Account Details\n";
    cout << "  3. Deposit Money\n";
    cout << "  4. Withdraw Money\n";
    cout << "  5. Transaction History\n";
    cout << "  6. Display All Accounts\n";
    cout << "  7. Delete Account\n";
    cout << "  8. Exit\n";
    cout << " ========================================\n";
}

int getMenuChoice(){
    int choice;

    while (true) {
        cout << " Enter your choice: ";

        if (cin >> choice) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return choice;
        }

        cout << " Invalid input! Please enter a number.\n";

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int main(){
    Bank bank("../data/accounts.txt");

    int choice;

    do {
        displayMenu();

        choice = getMenuChoice();

        switch (choice) {
            case 1:
                bank.createAccount();
                break;

            case 2:
                bank.displayAccount();
                break;

            case 3:
                bank.depositMoney();
                break;

            case 4:
                bank.withdrawMoney();
                break;

            case 5:
                bank.displayTransactionHistory();
                break;

            case 6:
                bank.displayAllAccounts();
                break;

            case 7:
                bank.deleteAccount();
                break;

            case 8:
                cout << "\n Thank you for using Banking Management System!\n";
                break;

            default:
                cout << " Invalid choice! Please select 1-8.\n";
        }

    } while (choice != 8);

    return 0;
}
