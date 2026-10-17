#include "Library.h"
#include <iostream>
#include <fstream>
#include <limits>
#include <algorithm>
#include <cctype>

using namespace std;

// Constructor
Library :: Library(const string& dataFile)
    : dataFile(dataFile){
    loadBooks();
}

// Find book by ID
Book* Library :: findBookById(int id){
    for (Book& book : books) {
        if (book.getId() == id) {
            return &book;
        }
    }

    return nullptr;
}

// Find book by ID - const version
const Book* Library :: findBookById(int id) const{
    for (const Book& book : books) {
        if (book.getId() == id) {
            return &book;
        }
    }

    return nullptr;
}

// Add a new book
void Library :: addBook(){
    cout << "\n --- Add Book ---\n";

    int id;

    while (true) {
        cout << " Enter book ID: ";

        if (cin >> id && id > 0) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }

        cout << " Invalid ID. Please enter a positive number!\n";

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    if (findBookById(id) != nullptr) {
        cout << " Error: A book with this ID already exists!\n";
        return;
    }

    string title;
    string author;
    string category;

    do {
        cout << " Enter book title: ";
        getline(cin, title);

        if (title.empty()) {
            cout << " Title cannot be empty!\n";
        }
    } while (title.empty());

    do {
        cout << " Enter author name: ";
        getline(cin, author);

        if (author.empty()) {
            cout << " Author name cannot be empty!\n";
        }
    } while (author.empty());

    do {
        cout << " Enter category: ";
        getline(cin, category);

        if (category.empty()) {
            cout << " Category cannot be empty!\n";
        }
    } while (category.empty());

    books.emplace_back(id, title, author, category);

    saveBooks();

    cout << " Book added successfully!\n";
}


// Remove a book
void Library :: removeBook(){
    cout << "\n --- Remove Book ---\n";

    int id;

    cout << " Enter book ID to remove: ";

    if (!(cin >> id)) {
        cout << " Invalid ID!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    auto it = find_if(
        books.begin(),
        books.end(),
        [id](const Book& book) {
            return book.getId() == id;
        }
    );

    if (it == books.end()) {
        cout << " Book with ID " << id << " was not found!\n";
        return;
    }

    cout << "\n Book found:\n";
    cout << " ----------------------------------------------\n";
    it->display();
    cout << " ----------------------------------------------\n";

    char confirmation;

    cout << " Are you sure you want to remove this book? (y/n): ";
    cin >> confirmation;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (confirmation == 'y' || confirmation == 'Y') {
        books.erase(it);
        saveBooks();

        cout << " Book removed successfully!\n";
    } else {
        cout << " Remove operation cancelled!\n";
    }
}


// Search for a book
void Library :: searchBook() const{
    cout << "\n --- Search Book ---\n";
    cout << "  1. Search by ID\n";
    cout << "  2. Search by Title\n";

    int choice;

    cout << " Enter your choice: ";

    if (!(cin >> choice)) {
        cout << " Invalid input!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (choice == 1) {
        int id;

        cout << " Enter book ID: ";

        if (!(cin >> id)) {
            cout << " Invalid ID!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        const Book* book = findBookById(id);

        if (book != nullptr) {
            cout << "\n Book found:\n";
            cout << " ----------------------------------------------\n";
            book->display();
            cout << " ----------------------------------------------\n";
        } else {
            cout << " Book with ID " << id << " was not found!\n";
        }
    }
    else if (choice == 2) {
        string searchTitle;

        cout << " Enter title to search: ";
        getline(cin, searchTitle);

        if (searchTitle.empty()) {
            cout << " Search title cannot be empty!\n";
            return;
        }

        bool found = false;

        for (const Book& book : books) {
            string title = book.getTitle();

            // Convert both strings to lowercase
            string lowerTitle = title;
            string lowerSearch = searchTitle;

            transform(
                lowerTitle.begin(),
                lowerTitle.end(),
                lowerTitle.begin(),
                [](unsigned char c) {
                    return static_cast<char>(tolower(c));
                }
            );

            transform(
                lowerSearch.begin(),
                lowerSearch.end(),
                lowerSearch.begin(),
                [](unsigned char c) {
                    return static_cast<char>(tolower(c));
                }
            );

            if (lowerTitle.find(lowerSearch) != string :: npos) {
                cout << "\n Book found:\n";
                cout << " ----------------------------------------------\n";
                book.display();
                cout << " ----------------------------------------------\n";

                found = true;
            }
        }

        if (!found) {
            cout << " No books matching that title were found!\n";
        }
    }
    else {
        cout << " Invalid choice!\n";
    }
}

// Issue a book
void Library :: issueBook(){
    cout << "\n --- Issue Book ---\n";

    int id;

    cout << " Enter book ID to issue: ";

    if (!(cin >> id)) {
        cout << " Invalid ID!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    Book* book = findBookById(id);

    if (book == nullptr) {
        cout << " Book with ID " << id << " was not found!\n";
        return;
    }

    if (book->isIssued()) {
        cout << " This book is already issued!\n";
        return;
    }

    book->issue();
    saveBooks();

    cout << " Book issued successfully!\n";
}

// Return a book
void Library :: returnBook(){
    cout << "\n --- Return Book ---\n";

    int id;

    cout << " Enter book ID to return: ";

    if (!(cin >> id)) {
        cout << "Invalid ID!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    Book* book = findBookById(id);

    if (book == nullptr) {
        cout << " Book with ID " << id << " was not found!\n";
        return;
    }

    if (!book->isIssued()) {
        cout << " This book is already available!\n";
        return;
    }

    book->returnBook();
    saveBooks();

    cout << " Book returned successfully!\n";
}

// Display all books
void Library :: displayAllBooks() const {
    cout << "\n --- All Books ---\n";

    if (books.empty()) {
        cout << " No books found in the library!\n";
        return;
    }

    for (const Book& book : books) {
        cout << "\n ----------------------------------------------\n";
        book.display();
    }

    cout << " ----------------------------------------------\n";
}

// Display only available books
void Library :: displayAvailableBooks() const {
    cout << "\n --- Available Books ---\n";

    bool found = false;

    for (const Book& book : books) {
        if (!book.isIssued()) {
            cout << "\n ----------------------------------------------\n";
            book.display();

            found = true;
        }
    }

    if (!found) {
        cout << " No available books found!\n";
    } else {
        cout << " ----------------------------------------------\n";
    }
}

// Save books to file
void Library :: saveBooks() const {
    ofstream file(dataFile);

    if (!file) {
        cout << " Error: Unable to open data file for writing!\n";
        return;
    }

    for (const Book& book : books) {
        file << book.toFileFormat() << '\n';
    }

    file.close();
}

// Load books from file
void Library :: loadBooks() {
    ifstream file(dataFile);

    if (!file) {
        return;
    }

    string line;

    while (getline(file, line)) {
        if (!line.empty()) {
            try {
                books.push_back(Book::fromFileFormat(line));
            }
            catch (const exception&) {
                cout << " Warning: Skipping invalid book record!\n";
            }
        }
    }

    file.close();
}
