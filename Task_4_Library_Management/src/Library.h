#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include <vector>
#include <string>

class Library{
    private:
        std::vector<Book> books;
        const std::string dataFile;

        Book* findBookById(int id);
        const Book* findBookById(int id) const;

    public:
        Library(const std::string& dataFile);

        void addBook();
        void removeBook();
        void searchBook() const;
        void issueBook();
        void returnBook();
        void displayAllBooks() const;
        void displayAvailableBooks() const;

        void saveBooks() const;
        void loadBooks();
};

#endif
