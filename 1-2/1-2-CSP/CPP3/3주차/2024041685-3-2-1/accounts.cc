#include <iostream>
#include "accounts.h"

void Account::setID(int id) {
	_id = id;
}

void Account::setBalance(int amount) {
	_balance = amount;
}

bool Account::deposit(int amount) {
	if (amount + _balance > 1000000) {
		return false;
	}
	_balance += amount;
	return true;
}

bool Account::withdraw(int amount) {
	if (_balance - amount < 0) {
		return false;
	}
	_balance -= amount;
	return true;
}

int Account::getID() {
	return _id;
}

int Account::getBalance() {
	return _balance;
}

bool AccountManager::createAccount() {
	if(accountNum >= 10) {
		return false;
	}
	accounts[accountNum].setID(accountNum);
	accounts[accountNum].setBalance(0);
	accountNum++;
	return true;
}

bool AccountManager::deposit(int id, int amount) {
	if (id >= accountNum || !(accounts[id].deposit(amount))) {
		return false;
	}
	return true;	
}

bool AccountManager::withdraw(int id, int amount) {
	if (id >= accountNum || !(accounts[id].withdraw(amount))) {
		return false;
	}
	return true;
}

bool AccountManager::transfer(int from, int to, int amount) {
	if (from >= accountNum || to >= accountNum) {
		return false;
	}
	if (!(accounts[from].withdraw(amount))) return false;
	if (!(accounts[to].deposit(amount))) {
		accounts[from].deposit(amount);
		return false;
	}
	return true;
}

void AccountManager::printAccount(int id) {
	if(id < accountNum) {
		std::cout << "Balance of user " << id << ": " << accounts[id].getBalance() << std::endl;
	}
}

int AccountManager::getMaxID() {
	return (accountNum - 1);
}

