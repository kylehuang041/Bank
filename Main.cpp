#include "User.h"
#include "ATMUser.h"
#include "ATM.h"
using namespace std;

void runATM();

int main() {
    runATM();
}

void runATM() {
    ATMUser* user = new ATMUser();
    ATM atm(user);
    delete user;
}