#include <iostream>
#include "ATM.h"

ATM::ATM() {
    std::cout << "\033[2J\033[1;1H";
    this->menu();
}

ATM::ATM(ATMUser* user) {
    std::cout << "\033[2J\033[1;1H";
    this->createAccount(user);
    this->menu();
}

void ATM::menu() {
    std::cout << "\033[2J\033[1;1H";
    std::cout << "------------------------------------\n";
    std::cout << "1. Sign In\n2. Create Account\n3. Exit\n";
    int res;
    std::cin >> res;
    switch(res) {
        case 1:
            std::cout << "\033[2J\033[1;1H";
            this->signIn();
            break;
        case 2:
            std::cout << "\033[2J\033[1;1H";
            this->createAccount();
            break;
        case 3:
            std::cout << "\033[2J\033[1;1H";
            this->exitProgram();
            break;
        default:
            std::cout << "\033[2J\033[1;1H";
            std::cout << "Please try again\n";
            this->menu();
            break;
    }
}

void ATM::subMenu() {
    std::cout << "\033[2J\033[1;1H";
    std::cout << "------------------------------------\n";
    std::cout << "1. Check Balance\n2. Deposit\n3. Withdraw\n";
    std::cout << "4. Account Information\n5. Log Out\n6. Exit\n";
    int res;
    std::cin >> res;
    switch(res) {
        case 1:
            std::cout << "\033[2J\033[1;1H";
            this->checkBalance();
            break;
        case 2:
            std::cout << "\033[2J\033[1;1H";
            this->deposit();
            break;
        case 3:
            std::cout << "\033[2J\033[1;1H";
            this->withdraw();
            break;
        case 4:
            std::cout << "\033[2J\033[1;1H";
            this->getInformation();
            break;
        case 5:
            std::cout << "\033[2J\033[1;1H";
            this->logOut();
            break;
        case 6:
            std::cout << "\033[2J\033[1;1H";
            this->exitProgram();
            break;
        default:
            std::cout << "\033[2J\033[1;1H";
            std::cout << "Please try again\n";
            this->subMenu();
            break;
    }
}

void ATM::signIn() {
    unsigned long int id;
    unsigned int pin;
    bool success = false;

    std::cout << "Enter your id number: ";
    std::cin >> id;
    std::cout << "Enter your pin: ";
    std::cin >> pin;

    int index = 0;
    while (index < this->accounts.size()) {
        if (this->accounts[index]->getId() == id && this->accounts[index]->getPin() == pin) {
            this->currentUser = this->accounts[index];
            success = true;
        }
        ++index;
    }
    std::cout << "\033[2J\033[1;1H";
    if (success) this->subMenu();
    else {
        std::cout << "Incorrect ID or pin. Please try again.\n";
        this->signIn();
    }
}

void ATM::createAccount() {
    std::cout << "\033[2J\033[1;1H";
    std::srand(time(NULL));
    std::string name, phone;
    unsigned long int id = std::rand();
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
    std::cout << "\033[2J\033[1;1H";
    this->menu();
}

void ATM::createAccount(ATMUser* user) {
    this->accounts.push_back(user);
    std::cout << "\033[2J\033[1;1H";
    this->menu();
}

void ATM::getInformation() {
    std::cout << "\033[2J\033[1;1H";
    std::cout << *(this->currentUser) << std::endl;
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

void ATM::checkBalance() {
    std::cout << "\033[2J\033[1;1H";
    std::cout << "Balance: " << this->currentUser->getBalance() << std::endl;
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

void ATM::deposit() {
    std::cout << "\033[2J\033[1;1H";
    long long int temp;
    std::cout << "Enter deposit amount: ";
    std::cin >> temp;
    this->currentUser->setBalance(temp);
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

void ATM::withdraw() {
    std::cout << "\033[2J\033[1;1H";
    long long int temp;
    std::cout << "Enter withdraw amount: ";
    std::cin >> temp;
    this->currentUser->setBalance(-temp);
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

void ATM::logOut() {
    std::cout << "\033[2J\033[1;1H";
    this->currentUser = NULL;
    this->menu();
}

void ATM::exitProgram() {
    for (int i = 0; i < this->accounts.size(); i++) {
        delete this->accounts[i];
    }
    std::exit(0);
}