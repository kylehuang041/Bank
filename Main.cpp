#include "User.h"
#include "ATMUser.h"
#include "ATM.h"
using namespace std;

int main() {
    ATMUser* user = new ATMUser("Bob", "4234235239", 5435435, 2342, 0);
    ATM atm(user);
}