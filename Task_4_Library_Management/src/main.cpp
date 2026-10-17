#include "Library.h"
#include <iostream>
#include <limits>

using namespace std;

void displayMenu(){
    cout << "\n ========================================\n";
    cout << "          LIBRARY MANAGEMENT SYSTEM\n";
    cout << " ========================================\n";
    cout << "  1. Add Book\n";
    cout << "  2. Remove Book\n";
    cout << "  3. Search Book\n";
    cout << "  4. Issue Book\n";
    cout << "  5. Return Book\n";
    cout << "  6. Display All Books\n";
    cout << "  7. Display Available Books\n";
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
    Library library("../data/books.txt");

    int choice;

    do {
        displayMenu();

        choice = getMenuChoice();

        switch (choice) {
            case 1:
                library.addBook();
                break;

            case 2:
                library.removeBook();
                break;

            case 3:
                library.searchBook();
                break;

            case 4:
                library.issueBook();
                break;

            case 5:
                library.returnBook();
                break;

            case 6:
                library.displayAllBooks();
                break;

            case 7:
                library.displayAvailableBooks();
                break;

            case 8:
                cout << "\n Thank you for using Library Management System!\n";
                break;

            default:
                cout << " Invalid choice! Please select 1-8.\n";
        }

    } while (choice != 8);

    return 0;
}
