#pragma once
#ifndef USER_H
#define USER_H

#include <iostream>

class User {
protected:
	std::string name;
	std::string phone;

public:
	User(const std::string &name, const std::string &phone);
	virtual ~User();
	virtual const std::string &getName();
	virtual void setName(const std::string &name);
	virtual const std::string &getPhone();
	virtual void setPhone(const std::string &phone);
};

#endif