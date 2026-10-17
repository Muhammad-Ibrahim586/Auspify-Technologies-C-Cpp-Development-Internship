#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <vector>

struct Transaction{
    std::string type;
    double amount;
    double balanceAfter;
};

class Account{
    private:
        int accountNumber;
        std::string holderName;
        std::string accountType;
        double balance;
        std::vector<Transaction> transactions;

    public:
        Account();
        Account(int accountNumber, std::string holderName, std::string accountType, double balance = 0.0);

        int getAccountNumber() const;
        std::string getHolderName() const;
        std::string getAccountType() const;
        double getBalance() const;

        bool deposit(double amount);
        bool withdraw(double amount);

        void displayDetails() const;
        void displayTransactions() const;

        std::string toFileFormat() const;
        static Account fromFileFormat(const std::string& line);
};

#endif
