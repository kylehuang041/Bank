#include "User.h"
#include "ATMUser.h"
#include "ATM.h"
using namespace std;

int main() {
    ATMUser user1;
    ATMUser* p_user1 = &user1;
    ATM atm(p_user1);
}
