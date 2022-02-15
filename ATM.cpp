#include <iostream>
#include "ATM.h"

// Source for clearing terminal: https://stackoverflow.com/questions/4062045/clearing-terminal-in-linux-with-c-code

ATM::ATM(ATMUser* user) {
    if (user != nullptr) this->createAccount(user);
    clearScreen();
    this->menu();
}

void ATM::menu() {
    clearScreen();
    std::cout << "------------------------------------\n";
    std::cout << "1. Sign In\n2. Create Account\n3. Check number of Users\n4. Exit\n";
    int res;
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
    std::cout << "1. Check Balance\n2. Deposit\n3. Withdraw\n";
    std::cout << "4. Account Information\n5. Log Out\n6. Exit\n";
    int res;
    std::cin >> res;
    switch(res) {
        case 1:
            clearScreen();
            this->checkBalance();
            break;
        case 2:
            clearScreen();
            this->deposit();
            break;
        case 3:
            clearScreen();
            this->withdraw();
            break;
        case 4:
            clearScreen();
            this->getInformation();
            break;
        case 5:
            clearScreen();
            this->logOut();
            break;
        case 6:
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
    unsigned long int id;
    unsigned int pin;

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
    int res;
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
        std::string name, phone;
        unsigned long int id = std::rand();
        while (isDuplicateId(id)) id = std::rand();
        unsigned int pin;

        std::cout << "Your ID number (DON'T FORGET!): " << id << std::endl;
        std::cout << "Enter your name: ";
        std::cin >> name;
        std::cout << "Enter your phone number: ";
        std::cin >> phone;
        std::cout << "Enter your pin: ";
        std::cin >> pin;

        ATMUser* temp = new ATMUser(name, phone, id, pin);
        this->accounts.push_back(temp);
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
    std::cout << *(this->currentUser) << std::endl;
    this->miniMenu1();
}

void ATM::checkBalance() {
    clearScreen();
    std::cout << "Balance: " << this->currentUser->getBalance() << std::endl;
    this->miniMenu1();
}

void ATM::deposit() {
    clearScreen();
    long long int temp;
    std::cout << "Enter deposit amount: ";
    std::cin >> temp;
    this->currentUser->setBalance(temp);
    this->miniMenu1();
}

void ATM::withdraw() {
    clearScreen();
    long long int temp;
    std::cout << "Enter withdraw amount: ";
    std::cin >> temp;
    this->currentUser->setBalance(-temp);
    this->miniMenu1();
}

void ATM::logOut() {
    clearScreen();
    this->currentUser = nullptr;
    this->menu();
}

void ATM::getNumberOfUsers() {
    clearScreen();
    std::cout << "Number of users: " << numberOfUsers << std::endl;
    std::cout << "1. Back\n2. Exit\n";
    int res;
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

// void ATM::createUser(ATMUser* user) {
//     this->accounts.push_back(user);
// }

void ATM::exitProgram() {
    clearScreen();
    for (int i = 0; i < this->accounts.size(); i++) {
        delete this->accounts[i];
    }
    std::exit(0);
}

void ATM::miniMenu1() {
    std::cout << "1. Back\n2. Exit\n";
    int res;
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

bool ATM::isDuplicateId(unsigned long int& id) {
    for (int i = 0; i < this->accounts.size(); i++)
        if (id == this->accounts[i]->getId()) return true;
    return false;
}

void clearScreen() {
    std::cout << "\033[2J\033[1;1H";
}

int ATM::numberOfUsers = 0;
// std::vector<ATMUsers*> ATM::this->accounts;