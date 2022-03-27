#include "User.h"
#include "ATMUser.h"
#include "ATM.h"
using namespace std;

int main() {
    // ATMUser* p_user1 = new ATMUser("bob", "7678677676", "12345678", "1234");
    // ATMUser* p_user2 = new ATMUser("sam", "3294892353", "123456789", "1234");
    // ATMUser* p_user3 = new ATMUser("jack", "3294892353", "123456789", "1234");
    ATMUser user1("bob", "7678677676", "12345678", "1234");
    ATMUser user2("sam", "3294892353", "123456789", "1234");
    ATMUser user3("jack", "3294892353", "123456789", "1234");
    ATMUser* p_user1 = &user1;
    ATMUser* p_user2 = &user2;
    ATMUser* p_user3 = &user3;
    ATM atm(p_user1, p_user2, p_user3, 0);
}