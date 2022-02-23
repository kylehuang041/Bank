#include "ATMUser.h"
#include <cmath>
#include <string>

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

std::string ATMUser::getBalance() {
    std::string temp = std::to_string(this->balance);
    if (temp.find(".")) temp = '$' + temp.substr(0, temp.find(".") + 3);
    return temp;
}

void ATMUser::setBalance(const long double& balance) {
    bool negative = (balance < 0) ? true : false;
    long double temp = round2(this->balance + balance);
    if (temp < 0) {
        std::cout << "Not enough money\n";
        return;
    } else this->balance = temp;
    if (negative) this->summary.push_back("-$" + std::to_string(-balance));
    else this->summary.push_back("+$" + std::to_string(balance));
}

void ATMUser::readSummary() {
    std::cout << "======Account Summary======\n";
    for (int i = 0; i < this->summary.size(); i++) {
        std::string temp = this->summary[i];
        if (temp.find(".")) temp = temp.substr(0, temp.find('.') + 3);
        std::cout << temp << std::endl;
    }
    std::cout << "===========================\n";
}

std::ostream& operator << (std::ostream& toString, const ATMUser& ATMUser) {
    toString << "name: " << ATMUser.name << "\nphone: " << ATMUser.phone
    << "\nid: " << ATMUser.id << "\npin: " << ATMUser.pin/* << "\nbalance: "
    << ATMUser.balance*/ << std::endl;
    return toString;
}

long double round2(long double value) {
    return std::round(value * 100.0) / 100.0;
}