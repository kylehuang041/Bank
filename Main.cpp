#include "./User/User.h"
#include "./ATM/ATMUser.h"
#include "./ATM/ATM.h"

using namespace std;

int main() {
	ATMUser user1("bob", "7678677676", "12345678", "1234");
	ATMUser user2("sam", "8795435345", "123456789", "1234");
	ATM atm(&user1, &user2, 0);
}