#include "ATMUser.h"
#include <cmath>

ATMUser::ATMUser(const std::string& name, const std::string& phone, const unsigned long int& id, const unsigned int& pin, const long double& balance) : User(name, phone) {
    this->id = id;
    this->pin = pin;
    this->balance = balance;
}

ATMUser::~ATMUser() {}

unsigned long int& ATMUser::getId() { return this->id; }

void ATMUser::setId(const unsigned long int& id) { this->id = id; }

unsigned int& ATMUser::getPin() { return this->pin; }

void ATMUser::setPin(const unsigned int& pin) { this->pin = pin; }

long double& ATMUser::getBalance() { return this->balance; }

void ATMUser::setBalance(const long double& balance) {
    long long int temp = (std::ceil(this->balance + balance) * 100) / 100;
    if (temp < 0) {
        std::cout << "Not enough money\n";
        return;
    }
    this->balance += balance;
}

std::ostream& operator << (std::ostream& toString, const ATMUser& ATMUser) {
    toString << "name: " << ATMUser.name << "\nphone: " << ATMUser.phone
    << "\nid: " << ATMUser.id << "\nphone: " << ATMUser.pin << "\nbalance: "
    << ATMUser.balance << std::endl;
    return toString;
}