#include <iostream>
#include "ATM.h"

ATM::ATM() {
    this->menu();
}

ATM::ATM(ATMUser user) {
    this->createAccount(user);
    this->menu();
}

void ATM::menu() {
    std::cout <<
    "
    ------------------------------------\n
    1. Sign In
    2. Create Account
    3. Exit
    ";
    int res;
    cin >> res;
    switch(res) {
        case 1:
            signIn();
            break;
        case 2:
            createAccount();
            break;
        case 3:
            exit();
            break;
        default:
            std::cout << "Please try again\n";
    }
    system("clear");
}

void ATM::void subMenu() {
    std::cout <<
    "
    ------------------------------------\n
    1. Check Balance\n
    2. Deposit\n
    3. Withdraw\n
    4. Account Information\n
    5. Log Out\n
    6. Exit\n
    ";
    int res;
    cin >> res;
    switch(res) {
        case 1:
            checkBalance();
            break;
        case 2:
            deposit();
            break;
        case 3:
            withdraw();
            break;
        case 4:
            getInformation();
            break;
        case 5:
            logOut();
            break;
        case 6:
            exit();
            break;
        default:
            std::cout << "Please try again\n";
            break;
    }
    system("clear");
}

void ATM::signIn() {
    unsigned long int id;
    unsigned int pin;
    bool success = false;

    std::cout << "Enter your id number: ";
    cin >> id;
    std::cout << "Enter your pin: ";
    cin >> pin;

    int index = 0;
    while (index < this->accounts.size()) {
        if (this->accounts[index].getId() == id) {
            this->currentUser = this->accounts[index];
            success = true;
        }
        ++index;
        index %= this->accounts.size() - 1;
    }
    if (success) this->subMenu();
    else this->signIn();
}

void ATM::createAccount() {
    std::srand(time(NULL));
    std::string name, phone;
    unsigned long int id = std::rand();
    unsigned int pin;

    std::cout << "Enter your name: ";
    cin >> name;
    std::cout << "Enter your phone number: ";
    cin >> phone;
    std::cout << "Enter your pin: ";
    cin >> pin;

    ATMUser temp(name, phone, id, pin, 0);
    this->accounts.add(temp);
    system("clear");
    this->menu();
}

void ATM::getInformation(ATMUser& user) {
    std::cout << user;
}

void ATM::checkBalance(ATMUser& user) {
    std::cout << this->currentUser.getBalance() << std::endl;
}

void deposit(const unsigned long long int& money) {
    this->currentUser->setBalance(money);
}

void withdraw(const unsigned long long int& money) {
    this->currentUser->setBalance(money);
}

void logOut() {
    this->currentUser = NULL;
}