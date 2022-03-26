#pragma once
#ifndef ATM_H
#define ATM_H

#include <iostream>
#include <vector>
#include "User.h"
#include "ATMUser.h"
#include <ctime>

class ATM {
    // private:
        static int numberOfUsers;
        static std::vector<ATMUser*> accounts;
        ATMUser* currentUser;
        void menu();
        void signIn();
        void createAccount(ATMUser* user = nullptr);
        void subMenu();
        void checkBalance();
        void deposit();
        void withdraw();
        void getInformation();
        void logOut();
        void exitProgram();
        void miniMenu1();
        bool isDuplicateId(const unsigned long int& id);
        void tryAgainMenu();
        void getNumberOfUsers();

    public:
        ATM(ATMUser* user = nullptr);
};

void clearScreen();
bool isNumber(const std::string& str); // source: https://www.delftstack.com/howto/cpp/how-to-determine-if-a-string-is-number-cpp/
bool isFourDigit(unsigned int pin);

#endif