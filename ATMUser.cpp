#include "ATMUser.h"

ATMUser::ATMUser(const std::string& name, const std::string& phone, const unsigned long int& id, const unsigned int& pin, const unsigned long long int& balance) : User(name, phone) {
    this->id = id;
    this->pin = pin;
    this->balance = balance;
}

ATMUser::~ATMUser() {}

unsigned long int& ATMUser::getId() { return this->id; }

void ATMUser::setId(const unsigned long int& id) { this->id = id; }

unsigned int& ATMUser::getPin() { return this->pin; }

void ATMUser::setPin(const unsigned int& pin) { this->pin = pin; }

unsigned long long int& ATMUser::getBalance() { return this->balance; }

void ATMUser::setBalance(const unsigned long long int& balance) { this->balance = balance; }

std::ostream& operator << (std::ostream& toString, const ATMUser& ATMUser) {
    toString << "name: " << ATMUser.name << "\nphone: " << ATMUser.phone
    << "\nid: " << ATMUser.id << "\nphone: " << ATMUser.pin << "\nbalance: "
    << ATMUser.balance << std::endl;
    return toString;
}