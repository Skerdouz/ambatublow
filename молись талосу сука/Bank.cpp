#include <iostream>
#include "Bank.h"


int Bank::getBalance() const {
	return (balance);
}

void Bank::setBalance(const int amount) 
{
	if (amount < 0) {
		std::cout << "Invalid amount. Balance cannot be negative." << std::endl;
		return;
	}
	balance = amount;
}

void Bank::addBalance(const int amount) {
	if (amount < 0) {
		std::cout << "Invalid amount. Balance cannot be negative." << std::endl;
		return;
	}
	balance += amount;
}

void Bank::subtractBalance(const int amount) {
	if (amount < 0) {
		std::cout << "Invalid amount. Balance cannot be negative." << std::endl;
		return;
	}
	balance -= amount;
}