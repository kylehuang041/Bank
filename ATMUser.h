#pragma once
#ifndef ATMUSER_H
#define ATMUSER_H

#include <iostream>
#include "User.h"
#include <vector>

class ATMUser : public User {
    // private:
        long double balance;
        unsigned long int id;
        unsigned int pin;
        std::vector<std::string> summary;

    public:
        ATMUser(const std::string& name = "John", const std::string& phone = "0123456789", const unsigned long int& id = 12345678, const unsigned int& pin = 1234, const long double& balance = 0);
        ~ATMUser();
        unsigned long int& getId();
        void setId(const unsigned long int& id);
        unsigned int& getPin();
        void setPin(const unsigned int& pin);
        std::string getBalance();
        void setBalance(const long double& balance);
        void readSummary();
        friend std::ostream& operator << (std::ostream& toString, const ATMUser& ATMUser);
};

long double round2(long double value);

#endif