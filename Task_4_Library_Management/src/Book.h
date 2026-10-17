#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book{
    private:
        int id;
        std::string title;
        std::string author;
        std::string category;
        bool issued;

    public:
        Book();
        Book(int id, std::string title, std::string author, std::string category, bool issued = false);

        int getId() const;
        std::string getTitle() const;
        std::string getAuthor() const;
        std::string getCategory() const;
        bool isIssued() const;

        void setTitle(std::string title);
        void setAuthor(std::string author);
        void setCategory(std::string category);
        void setIssued(bool issued);

        void issue();
        void returnBook();

        void display() const;

        std::string toFileFormat() const;
        static Book fromFileFormat(const std::string& line);
};

#endif
