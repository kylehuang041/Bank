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
        std::vector<ATMUser> accounts;
        ATMUser* currentUser;

    public:
        ATM();
        ATM(ATMUser user);
        void menu();
        void signIn();
        void createAccount();
        void createAccount(ATMUser user);
        void subMenu();
        void checkBalance();
        void Deposit();
        void Withdraw();
        void getInformation();
        void logOut();
        // void exit();
};

#endif