#ifndef BANK_H
#define BANK_H

#include "Account.h"
#include <string>
#include <vector>

class Bank{
    private:
        std::vector<Account> accounts;
        const std::string dataFile;

        Account* findAccountByNumber(int accountNumber);
        const Account* findAccountByNumber(int accountNumber) const;

        int getValidAccountNumber(const std::string& prompt) const;
        double getValidAmount(const std::string& prompt) const;
        std::string getNonEmptyString(const std::string& prompt) const;

    public:
        Bank(const std::string& dataFile);

        void createAccount();
        void displayAccount() const;
        void depositMoney();
        void withdrawMoney();
        void displayTransactionHistory() const;
        void displayAllAccounts() const;
        void deleteAccount();

        void saveAccounts() const;
        void loadAccounts();
};

#endif
