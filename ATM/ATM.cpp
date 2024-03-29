#include "ATM.h"

ATM::ATM(ATMUser *user, ...) {
	va_list list;
	va_start(list, user);

	while (user) {
		this->createAccount(user);
		user = va_arg(list, ATMUser *);
	}

	va_end(list);
	clearScreen();
	this->menu();
}

ATM::~ATM() {
	this->exitProgram();
	std::cout << "destructor\n";
}

// Main Functions

void ATM::menu() {
	clearScreen();
	std::cout << "------------------------------------\n";
	std::cout << "1. Sign In\n2. Create Account\n3. Check number of users\n4. Exit\n";
	int res{};
	std::cin >> res;
	switch (res){
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
	std::cout << "1. Balance\n2. Account Summary\n3. Deposit\n4. Withdraw\n";
	std::cout << "5. Account Information\n6. Log Out\n7. Exit\n";
	int res{};
	std::cin >> res;
	switch (res) {
	case 1:
		clearScreen();
		this->checkBalance();
		break;
	case 2:
		clearScreen();
		this->currentUser->readSummary();
		this->miniMenu1();
		break;
	case 3:
		clearScreen();
		this->deposit();
		break;
	case 4:
		clearScreen();
		this->withdraw();
		break;
	case 5:
		clearScreen();
		this->getInformation();
		break;
	case 6:
		clearScreen();
		this->logOut();
		break;
	case 7:
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
	std::string id{};
	std::string pin{};

	std::cout << "Enter your id number: ";
	std::cin >> id;
	std::cout << "Enter your pin: ";
	std::cin >> pin;

	int index = 0;
	while (index < this->accounts.size())	{
		if ((this->accounts[index]->getId().compare(id) == 0) && this->accounts[index]->getPin() == pin) {
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
	int res{};
	std::cin >> res;
	clearScreen();
	if (res == 1) this->signIn();
	else if (res == 2) this->menu();
	else tryAgainMenu();
}

void ATM::createAccount(ATMUser *user) {
	++numberOfUsers;
	if (user == nullptr) {
		clearScreen();
		std::string name{}, phone{};
		std::string id = this->createRandomID();
		while (isDuplicateId(id))	id = this->createRandomID();
		std::string pin{};

		std::cout << "Your ID number (DON'T FORGET!): " << id << std::endl;
		std::cout << "Enter your name: ";
		while (std::cin >> name) {
			if (!isNumber(name)) break;
			else std::cout << "Enter letters only for name: ";
		}
		std::cout << "Enter your phone number: ";
		while (std::cin >> phone)	{
			if (isNumber(phone)) break;
			else std::cout << "Enter only integers for phone number: ";
		}
		std::cout << "Enter your 4-digit number pin: ";
		while (std::cin >> pin)	{
			if (isNumber(pin) && pin.length() == 4)	break;
			else std::cout << "Enter only 4 integers for pin number: ";
		}

		ATMUser newUser(name, phone, id, pin);
		ATMUser *p_newUser = &newUser;
		this->accounts.push_back(p_newUser);
		clearScreen();
		this->menu();
	}
	else {
		bool duplicate = false;
		std::string newID{};
		while (isDuplicateId(user->getId())) {
			duplicate = true;
			newID = this->createRandomID();
			user->setId(newID);
		}
		if (duplicate) {
			std::cout << "Duplicate ID error: here is a new ID (DON'T FORGET): "
								<< newID << " for " << user->getName() << std::endl;
			std::cout << "Press Enter to continue\n";
			std::cin.ignore();
		}
		this->accounts.push_back(user);
	}
}

void ATM::getInformation() {
	clearScreen();
	try	{
		std::cout << *(this->currentUser) << std::endl;
	}
	catch (...)	{
		std::cout << "Error: currentUser is NULL\n";
	}
	this->miniMenu1();
}

void ATM::checkBalance() {
	clearScreen();
	if (this->currentUser == nullptr)
	{
		std::cout << "Error: undefined reference from currentUser\n";
		return;
	}
	std::cout << "Balance: " << this->currentUser->getBalance() << std::endl;
	this->miniMenu1();
}

void ATM::deposit() {
	clearScreen();
	long double temp{};
	std::cout << "Enter deposit amount: ";
	std::cin >> temp;
	this->currentUser->setBalance(temp);
	this->miniMenu1();
}

void ATM::withdraw() {
	clearScreen();
	long double temp{};
	std::cout << "Enter withdraw amount: ";
	std::cin >> temp;
	this->currentUser->setBalance(-temp);
	this->miniMenu1();
}

void ATM::getNumberOfUsers() {
	clearScreen();
	std::cout << "Number of users: " << numberOfUsers << std::endl;
	std::cout << "1. Back\n2. Exit\n";
	int res{};
	std::cin >> res;
	switch (res) {
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

// Helper Functions

// Source: https://stackoverflow.com/questions/13445688/how-to-generate-a-random-number-in-c
std::string ATM::createRandomID() {
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist6(0, 9);
	std::uniform_int_distribution<std::mt19937::result_type> dist6v2(8, 11);

	std::string randomID{};
	int length = dist6v2(rng);
	for (int i = 0; i < length; i++) {
		randomID += std::to_string(dist6(rng));
	}
	return randomID;
}

void ATM::logOut() {
	clearScreen();
	if (this->currentUser != nullptr)	this->currentUser = nullptr;
	this->menu();
}

void ATM::miniMenu1() {
	std::cout << "1. Back\n2. Exit\n";
	int res{};
	std::cin >> res;
	switch (res) {
	case 1:
		this->subMenu();
		break;
	case 2:
		this->exitProgram();
		break;
	}
}

bool ATM::isDuplicateId(const std::string &id) {
	for (int i = 0; i < this->accounts.size(); ++i)
		if (id.compare(this->accounts[i]->getId()) == 0)
			return true;
	return false;
}

void ATM::exitProgram() {
	clearScreen();
	this->accounts.clear();
	std::exit(0);
}

// Source for clearing terminal: https://stackoverflow.com/questions/4062045/clearing-terminal-in-linux-with-c-code
void clearScreen() {
	std::cout << "\033[2J\033[1;1H";
}

// source: https://www.delftstack.com/howto/cpp/how-to-determine-if-a-string-is-number-cpp/
bool isNumber(const std::string &str) {
	return str.find_first_not_of("0123456789") == std::string::npos;
}

int ATM::numberOfUsers = 0;
std::vector<ATMUser *> ATM::accounts{};