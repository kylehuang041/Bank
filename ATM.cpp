#include <iostream>
#include "ATM.h"

ATM::ATM() {
    system("clear");
    this->menu();
}

ATM::ATM(ATMUser user) {
    system("clear");
    this->createAccount(user);
    this->menu();
}

void ATM::menu() {
    system("clear");
    std::cout << "------------------------------------\n";
    std::cout << "1. Sign In\n2. Create Account\n3. Exit\n";
    int res;
    std::cin >> res;
    switch(res) {
        case 1:
            system("clear");
            this->signIn();
            break;
        case 2:
            system("clear");
            this->createAccount();
            break;
        case 3:
            system("clear");
            exit(0);
            break;
        default:
            system("clear");
            std::cout << "Please try again\n";
            this->menu();
            break;
    }
}

void ATM::subMenu() {
    system("clear");
    std::cout << "------------------------------------\n";
    std::cout << "1. Check Balance\n2. Deposit\n3. Withdraw\n";
    std::cout << "4. Account Information\n5. Log Out\n6. Exit\n";
    int res;
    std::cin >> res;
    switch(res) {
        case 1:
            system("clear");
            this->checkBalance();
            break;
        case 2:
            system("clear");
            this->deposit();
            break;
        case 3:
            system("clear");
            this->withdraw();
            break;
        case 4:
            system("clear");
            this->getInformation();
            break;
        case 5:
            system("clear");
            this->logOut();
            break;
        case 6:
            system("clear");
            exit(0);
            break;
        default:
            system("clear");
            std::cout << "Please try again\n";
            this->subMenu();
            break;
    }
}

void ATM::signIn() {
    system("clear");
    unsigned long int id;
    unsigned int pin;
    bool success = false;

    std::cout << "Enter your id number: ";
    std::cin >> id;
    std::cout << "Enter your pin: ";
    std::cin >> pin;

    int index = 0;
    while (index < this->accounts.size()) {
        if (this->accounts[index].getId() == id) {
            this->currentUser = this->accounts[index];
            success = true;
        }
        ++index;
        index %= this->accounts.size() - 1;
    }
    system("clear");
    if (success) this->subMenu();
    else this->signIn();
}

void ATM::createAccount() {
    system("clear");
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


    ATMUser temp(name, phone, id, pin, 0);
    this->accounts.push_back(temp);
    system("clear");
    this->menu();
}

void ATM::createAccount(ATMUser& user) {
    this->accounts.push_back(user);
    system("clear");
    this->menu();
}

void ATM::getInformation(ATMUser& user) {
    system("clear");
    std::cout << user;
}

void ATM::checkBalance(ATMUser& user) {
    system("clear");
    std::cout << this->currentUser.getBalance() << std::endl;
}

void deposit(const unsigned long long int& money) {
    system("clear");
    this->currentUser->setBalance(money);
}

void withdraw(const unsigned long long int& money) {
    system("clear");
    this->currentUser->setBalance(money);
}

void logOut() {
    system("clear");
    this->currentUser = NULL;
}