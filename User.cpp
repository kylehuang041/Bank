#include "User.h"

User::User(const std::string& name, const std::string& phone) {
    this->name = name;
    this->phone = phone;
}

User::~User() {}

const std::string& User::getName() { return this->name; }

void User::setName(const std::string& name) { this->name = name; }

const std::string& User::getPhone() { return this->phone; }

void User::setPhone(const std::string& phone) { this->phone = phone; }