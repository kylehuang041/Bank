#pragma once
#ifndef ATMUSER_H
#define ATMUSER_H

#include <iostream>
#include "User.h"

class ATMUser : public User {
    // private:
        unsigned long long int balance;
        unsigned long int id;
        unsigned int pin;

    public:
        ATMUser(const std::string& name, const std::string& phone, const unsigned long int& id, const unsigned int& pin, const unsigned long long int& balance);
        ~ATMUser();
        unsigned long int& getId();
        void setId(const unsigned long int& id);
        unsigned int& getPin();
        void setPin(const unsigned int& pin);
        unsigned long long int& getBalance();
        void setBalance(const unsigned long long int& balance);
        friend std::ostream& operator << (std::ostream& toString, const ATMUser& ATMUser);
};

#endif