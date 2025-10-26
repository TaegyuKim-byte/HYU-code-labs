#include <iostream>
#include "accounts.h"
#include <sstream>

int main() {
	AccountManager manager;
	std::string input;
	
	while (true) {

		std::cout << "Job?" << std::endl;

		std::getline(std::cin, input);
		std::istringstream iss(input);

		char command;
		iss >> command;

		if (command == 'Q') break;

		if (command == 'N') {
			if (manager.createAccount()) {
				std::cout << "Success!" << std::endl;
				manager.printAccount(manager.getMaxID());	
			} else {
				std::cout << "Failure!" << std::endl;
			}
		} else if (command == 'D') {
			int id, amount;
			iss >> id >> amount;
			if (manager.deposit(id, amount)) {
				std::cout << "Success!" << std::endl;
				manager.printAccount(id);
			} else {
				std::cout << "Failure!" << std::endl;
				if ( id < manager.getMaxID()+1) {
					manager.printAccount(id);
				}
			}
		} else if (command == 'W') {
			int id, amount;
			iss >> id >> amount;
			if (manager.withdraw(id, amount)) {
				std::cout << "Success!" << std::endl;
				manager.printAccount(id);
			} else {
				std::cout << "Failure!" << std::endl;
				if ( id < manager.getMaxID()+1) {
					manager.printAccount(id);
				}
			}
		} else if (command == 'T') {
			int from, to, amount;
			iss >> from >> to >> amount;
			if (manager.transfer(from, to, amount)) {
				std::cout << "Success!" << std::endl;
				if ( from < to ) {
					manager.printAccount(from);
					manager.printAccount(to);
				} else {
					manager.printAccount(to);
					manager.printAccount(from);
				}
			} else {
				std::cout << "Failure!" << std::endl;
				if ( from < manager.getMaxID()+1 && to < manager.getMaxID()+1 ) {
					if ( from < to) {
						manager.printAccount(from);
						manager.printAccount(to);
					} else {
						manager.printAccount(to);
						manager.printAccount(from);
					}
				}
			}
		}
	}
	return 0;
}

