#include <iostream>
#include "intset.h"

void intset::AddNumber(int num) {
	for (int i = 0; i < numbers_.size(); i++) {
		if (num == numbers_[i]) return ;
	}

	numbers_.push_back(num);
}

void intset::DeleteNumber(int num) {
	for (int i = 0; i < numbers_.size(); ) {
		if (num == numbers_[i]) {
			numbers_.erase(numbers_.begin() + i);
		}
		else {
			i++;
		}
	}
}

int intset::GetItem(int pos) {
	if (pos <= numbers_.size()) {
		return numbers_[pos];
	}
	else {
		return -1;
	}
}

std::vector<int> intset::GetAll() {
	return numbers_;
}

