#pragma once
#ifndef ATM_H
#define ATM_H

#include <iostream>
#include <vector>
#include <random>
#include <string>
#include <cstdarg>
#include "User.h"
#include "ATMUser.h"

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
        void getNumberOfUsers();

        std::string createRandomID(); // source: https://stackoverflow.com/questions/13445688/how-to-generate-a-random-number-in-c
        void logOut();
        void exitProgram();
        void miniMenu1();
        bool isDuplicateId(const std::string& id);
        void tryAgainMenu();

    public:
        ATM(ATMUser* s, ...);
        ~ATM();
};

void clearScreen(); // source for clearing terminal: https://stackoverflow.com/questions/4062045/clearing-terminal-in-linux-with-c-code
bool isNumber(const std::string& str); // source: https://www.delftstack.com/howto/cpp/how-to-determine-if-a-string-is-number-cpp/

#endif