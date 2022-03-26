#include "User.h"
#include "ATMUser.h"
#include "ATM.h"
using namespace std;

int main() {
    // ATMUser user1;
    // ATMUser* p_user1 = &user1;
    // ATM atm(p_user1);

    ATMUser* p_user1 = new ATMUser("bob", "7678677676", 12345678, 1234);
    ATMUser* p_user2 = new ATMUser("sam", "3294892353", 123456789, 1234);
    ATM atm(p_user1, p_user2, 0);
}
