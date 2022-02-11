#include "User.h"

User::User(const std::string& name, const std::string& phone) {
    this->name = name;
    this->phone = phone;
}

User::~User() {}

std::string& User::getName() { return this->name; }

void User::setName(const std::string& name) { this->name = name; }

std::string& User::getPhone() { return this->phone; }

void User::setPhone(const std::string& phone) { this->phone = phone; }

// std::ostream& operator << (std::ostream& toString, const User user) {
//     toString << "name: " << user.name << "\nphone: " << user.phone << std::endl;
//     return toString;
// }