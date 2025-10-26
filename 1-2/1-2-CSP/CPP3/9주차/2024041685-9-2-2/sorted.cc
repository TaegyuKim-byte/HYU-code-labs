#include "sorted.h"
#include <iostream>
#include <vector>
#include <set>

//member variable : std::vector<int> numbers_

void SortedArray::AddNumber(int num) {
	numbers_.push_back(num);
}

std::vector<int> SortedArray::GetSortedAscending() {
	std::multiset<int> ms;
	std::vector<int> numbers_2;
	std::vector<int>::iterator it;
	std::multiset<int>::iterator it2;


	for (it = numbers_.begin(); it != numbers_.end(); it++) {
		ms.insert(*it);
	}

	for (it2 = ms.begin(); it2 != ms.end(); it2++) {
		numbers_2.push_back(*it2);
	}

	return numbers_2;
}

std::vector<int> SortedArray::GetSortedDescending() {
	std::multiset<int> ms;
	std::vector<int> numbers_2;
	std::vector<int>::iterator it;
	std::multiset<int>::reverse_iterator it2;

	for (it = numbers_.begin(); it != numbers_.end(); it++) {
		ms.insert(*it);
	}

	for (it2 = ms.rbegin(); it2 != ms.rend(); it2++) {
		numbers_2.push_back(*it2);
	}

	return numbers_2;
}

int SortedArray::GetMax() {
	std::vector<int> vec0;
	std::vector<int>::iterator it;

	vec0 = this->GetSortedDescending();
	
	it = vec0.begin();

	return *it;
}

int SortedArray::GetMin() {
	std::vector<int> vec0;
	std::vector<int>::iterator it;

	vec0 = this->GetSortedAscending();

	it = vec0.begin();

	return *it;
}