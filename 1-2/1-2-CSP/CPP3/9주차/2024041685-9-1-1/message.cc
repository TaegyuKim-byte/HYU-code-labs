#include "message.h"

void MessageBook::AddMessage(int number, const std::string& message) {
	messages_[number] = message;
}

void MessageBook::DeleteMessage(int number) {
	auto it = messages_.find(number);

	if (it != messages_.end()) {
		messages_.erase(number);
	}
}

std::vector<int> MessageBook::GetNumbers() {
	
	std::vector<int> phoneNum;
	
	for (auto it = messages_.begin(); it != messages_.end(); it++) {
		phoneNum.push_back(it -> first);
	}

	return phoneNum;

}

const std::string& MessageBook::GetMessage(int number) {
	
	if (messages_.find(number) != messages_.end()) {
		return messages_[number];
	}
	else {
		static const std::string empty_string = "";
		return empty_string;
	}

}

