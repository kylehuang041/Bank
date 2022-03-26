#include <iostream>
#include "ATM.h"
#include <string>

ATM::ATM(ATMUser* user) {
    if (user != nullptr) this->createAccount(user);
    clearScreen();
    this->menu();
}

void ATM::menu() {
    clearScreen();
    std::cout << "------------------------------------\n";
    std::cout << "1. Sign In\n2. Create Account\n3. Check number of users\n4. Exit\n";
    int res{};
    std::cin >> res;
    switch(res) {
        case 1:
            clearScreen();
            this->signIn();
            break;
        case 2:
            clearScreen();
            this->createAccount();
            break;
        case 3:
            this->getNumberOfUsers();
            break;
        case 4:
            clearScreen();
            this->exitProgram();
            break;
        default:
            clearScreen();
            std::cout << "Please try again\n";
            this->menu();
            break;
    }
}

void ATM::subMenu() {
    clearScreen();
    std::cout << "------------------------------------\n";
    std::cout << "1. Balance\n2. Account Summary\n3. Deposit\n4. Withdraw\n";
    std::cout << "5. Account Information\n6. Log Out\n7. Exit\n";
    int res{};
    std::cin >> res;
    switch(res) {
        case 1:
            clearScreen();
            this->checkBalance();
            break;
        case 2:
            clearScreen();
            this->currentUser->readSummary();
            this->miniMenu1();
            break;
        case 3:
            clearScreen();
            this->deposit();
            break;
        case 4:
            clearScreen();
            this->withdraw();
            break;
        case 5:
            clearScreen();
            this->getInformation();
            break;
        case 6:
            clearScreen();
            this->logOut();
            break;
        case 7:
            clearScreen();
            this->exitProgram();
            break;
        default:
            clearScreen();
            std::cout << "Please try again\n";
            this->subMenu();
            break;
    }
}

void ATM::signIn() {
    unsigned long int id{};
    unsigned int pin{};

    std::cout << "Enter your id number: ";
    std::cin >> id;
    std::cout << "Enter your pin: ";
    std::cin >> pin;

    int index = 0;
    while (index < this->accounts.size()) {
        if (this->accounts[index]->getId() == id && this->accounts[index]->getPin() == pin) {
            this->currentUser = this->accounts[index];
            clearScreen();
            std::cout << "Hello " << this->accounts[index]->getName() << std::endl;
            this->subMenu();
            return;
        }
        ++index;
    }
    this->tryAgainMenu();
}

void ATM::tryAgainMenu() {
    clearScreen();
    std::cout << "Incorrect ID or pin. Please try again.\n";
    std::cout << "1. Try again\n2. Back\n";
    int res{};
    std::cin >> res;
    clearScreen();
    if (res == 1) this->signIn();
    else if (res == 2) this->menu();
    else tryAgainMenu();
}

void ATM::createAccount(ATMUser* user) {
    ++numberOfUsers;
    if (user == nullptr) {
        clearScreen();
        std::srand(time(NULL));
        std::string name{}, phone{};
        unsigned long int id = std::rand();
        while (isDuplicateId(id)) id = std::rand();
        std::string pin{};

        std::cout << "Your ID number (DON'T FORGET!): " << id << std::endl;
        std::cout << "Enter your name: ";
        while (std::cin >> name) {
            if (!isNumber(name)) break;
            else std::cout << "Enter letters only for name: ";
        }
        std::cout << "Enter your phone number: ";
        while (std::cin >> phone) {
            if (isNumber(phone)) break;
            else std::cout << "Enter only integers for phone number: ";
        }
        std::cout << "Enter your 4-digit number pin: ";
        while (std::cin >> pin) {
            if (isNumber(pin) && isFourDigit(std::stoi(pin))) break;
            else std::cout << "Enter only 4 integers for pin number: ";
        }

        ATMUser temp(name, phone, id, std::stoi(pin));
        ATMUser* p_temp = &temp;
        this->accounts.push_back(p_temp);
        clearScreen();
        this->menu();
    } else {
        this->accounts.push_back(user);
        clearScreen();
        this->menu();
    }
}

void ATM::getInformation() {
    clearScreen();
    try {
        std::cout << *(this->currentUser) << std::endl;
    } catch (...) {
        std::cout << "Error: currentUser is NULL\n";
    }
    this->miniMenu1();
}

void ATM::checkBalance() {
    clearScreen();
    if (this->currentUser == nullptr) {
        std::cout << "Error: undefined reference from currentUser\n";
        return;
    }
    std::cout << "Balance: " << this->currentUser->getBalance() << std::endl;
    this->miniMenu1();
}

void ATM::deposit() {
    clearScreen();
    long double temp{};
    std::cout << "Enter deposit amount: ";
    std::cin >> temp;
    this->currentUser->setBalance(temp);
    this->miniMenu1();
}

void ATM::withdraw() {
    clearScreen();
    long double temp{};
    std::cout << "Enter withdraw amount: ";
    std::cin >> temp;
    this->currentUser->setBalance(-temp);
    this->miniMenu1();
}

void ATM::logOut() {
    clearScreen();
    if (this->currentUser != nullptr) this->currentUser = nullptr;
    this->menu();
}

void ATM::getNumberOfUsers() {
    clearScreen();
    std::cout << "Number of users: " << numberOfUsers << std::endl;
    std::cout << "1. Back\n2. Exit\n";
    int res{};
    std::cin >> res;
    switch(res) {
        case 1:
            clearScreen();
            this->menu();
            break;
        case 2:
            clearScreen();
            this->exitProgram();
            break;
    }
}

void ATM::miniMenu1() {
    std::cout << "1. Back\n2. Exit\n";
    int res{};
    std::cin >> res;
    switch(res) {
        case 1:
            this->subMenu();
            break;
        case 2:
            this->exitProgram();
            break;
    }
}

bool ATM::isDuplicateId(const unsigned long int& id) {
    for (int i = 0; i < this->accounts.size(); ++i)
        if (id == this->accounts[i]->getId()) return true;
    return false;
}

void ATM::exitProgram() {
    clearScreen();
    // for (int i = 0; i < this->accounts.size(); i++) {
        // delete this->accounts[i];
        // this->accounts[i] = nullptr;
    // }
    this->accounts.clear();
    std::exit(0);
}

void clearScreen() {
    // Source for clearing terminal: https://stackoverflow.com/questions/4062045/clearing-terminal-in-linux-with-c-code
    std::cout << "\033[2J\033[1;1H";
}

// source: https://www.delftstack.com/howto/cpp/how-to-determine-if-a-string-is-number-cpp/
bool isNumber(const std::string& str) {
    return str.find_first_not_of("0123456789") == std::string::npos;
}

bool isFourDigit(unsigned int pin) {
    int counter = 0;
    while (pin > 0) {
        pin /= 10;
        ++counter;
    }
    return (counter == 4);
}

int ATM::numberOfUsers = 0;
std::vector<ATMUser*> ATM::accounts {};