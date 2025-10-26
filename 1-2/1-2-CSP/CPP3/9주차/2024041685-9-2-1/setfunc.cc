#include "setfunc.h"
#include <iostream>
#include <set>
#include <string>
#include <sstream>

std::set<int> parseSet(const std::string& str) { // str = {  }
	std::set<int> resultSet;
	std::istringstream ss(str);
	char ch;
	int num;

	while (ss >> ch) {
		if (isdigit(ch) || ch == '-') {
			ss.putback(ch);
			ss >> num;
			resultSet.insert(num);
		}
	}

	return resultSet;
}

void printSet(const std::set<int>& set) {
	std::set<int>::iterator it;

	std::cout << "{ ";
	for (it = set.begin(); it != set.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << "}\n";
}

std::set<int> getIntersection(const std::set<int>& set0, const std::set<int>& set1) {
	std::set<int> set2;
	std::set<int>::iterator it;
	std::set<int>::iterator it2;


	for (it = set0.begin(); it != set0.end(); it++) {
		it2 = set1.find(*it);
		if (it2 != set1.end()) set2.insert(*it2);
	}

	return set2;
}

std::set<int> getUnion(const std::set<int>& set0, const std::set<int>& set1) {
	std::set<int> set2;
	std::set<int>::iterator it;

	for (it = set0.begin(); it != set0.end(); it++) {
		set2.insert(*it);
	} 
	for (it = set1.begin(); it != set1.end(); it++) {
		set2.insert(*it);
	}

	return set2;
}

std::set<int> getDifference(const std::set<int>& set0, const std::set<int>& set1) {
	std::set<int> set2;
	std::set<int>::iterator it;
	std::set<int>::iterator it2;


	for (it = set0.begin(); it != set0.end(); it++) {
		it2 = set1.find(*it);
		if (it2 == set1.end()) set2.insert(*it);
	}

	return set2;
}