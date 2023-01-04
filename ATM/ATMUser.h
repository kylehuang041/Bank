#pragma once
#ifndef ATMUSER_H
#define ATMUSER_H

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include "./../User/User.h"

class ATMUser : public User {
	long double balance;
	std::string id;
	std::string pin;
	std::vector<std::string> summary;

public:
	ATMUser(const std::string &name, const std::string &phone, const std::string &id, const std::string &pin = "1234", const long double &balance = 0);
	~ATMUser();
	const std::string &getId();
	void setId(const std::string &id);
	const std::string &getPin();
	void setPin(const std::string &pin);
	std::string getBalance();
	void setBalance(const long double &balance);
	void readSummary();
	friend std::ostream &operator<<(std::ostream &toString, const ATMUser &
		ATMUser);
};

long double round2(long double value);

#endif