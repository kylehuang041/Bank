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
        std::vector<ATMUser*> accounts;
        ATMUser* currentUser;
        void menu();
        void signIn();
        // void createAccount();
        void createAccount(ATMUser* user = nullptr);
        void subMenu();
        void checkBalance();
        void deposit();
        void withdraw();
        void getInformation();
        void logOut();
        void exitProgram();
        void miniMenu1();
        bool isDuplicateId(unsigned long int& id);
        void tryAgainMenu();

    public:
        ATM(ATMUser* user = nullptr);
        
};

#endif