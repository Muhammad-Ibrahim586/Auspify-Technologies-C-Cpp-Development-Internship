#include "Book.h"
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

// Default constructor
Book :: Book()
    : id(0), title(""), author(""), category(""), issued(false) {}

// Parameterized constructor
Book :: Book(int id, string title, string author, string category, bool issued)
    : id(id), title(title), author(author), category(category), issued(issued) {}

// Getter functions
int Book :: getId() const{
    return id;
}

string Book :: getTitle() const{
    return title;
}

string Book :: getAuthor() const{
    return author;
}

string Book :: getCategory() const{
    return category;
}

bool Book :: isIssued() const{
    return issued;
}

// Setter functions
void Book :: setTitle(string title){
    this->title = title;
}

void Book :: setAuthor(string author){
    this->author = author;
}

void Book :: setCategory(string category){
    this->category = category;
}

void Book :: setIssued(bool issued){
    this->issued = issued;
}

// Issue the book
void Book :: issue(){
    issued = true;
}

// Return the book
void Book :: returnBook(){
    issued = false;
}

// Display book information
void Book :: display() const{
    cout << " Book ID: " << id;
    cout << " | Title: " << title << endl;
    cout << " Author: " << author;
    cout << " | Category: " << category << endl;
    cout << " Status: " << (issued ? "Issued" : "Available") << endl;
}

// Convert book data into file format
string Book :: toFileFormat() const{
    ostringstream output;

    output << id << "|" << title << "|" << author << "|" << category << "|" << issued;

    return output.str();
}

// Create a Book object from a saved file line
Book Book :: fromFileFormat(const string& line){
    stringstream input(line);

    string idString;
    string title;
    string author;
    string category;
    string issuedString;

    getline(input, idString, '|');
    getline(input, title, '|');
    getline(input, author, '|');
    getline(input, category, '|');
    getline(input, issuedString, '|');

    int id = stoi(idString);
    bool issued = (issuedString == "1");

    return Book(id, title, author, category, issued);
}
