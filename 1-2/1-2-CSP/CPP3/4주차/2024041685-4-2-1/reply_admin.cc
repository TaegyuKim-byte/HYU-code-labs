#include "reply_admin.h"
#include <string>
#define NUM_OF_CHAT 10
#include <iostream>
#include <algorithm>

ReplyAdmin::ReplyAdmin() {
	num_chats = 0;
	chats = new std::string[NUM_OF_CHAT];
}

ReplyAdmin::~ReplyAdmin() {
	delete[] chats;
}


int ReplyAdmin::getChatCount() {
	return num_chats;

}

bool ReplyAdmin::addChat(std::string _chat) {
	if (num_chats >= NUM_OF_CHAT) {
		return false;
	}
	chats[num_chats] = _chat;
	num_chats += 1;
	return true;
}

bool ReplyAdmin::removeChat(int _index) {
	if (_index >= num_chats || _index < 0) {
		return false;
	}
	for (int i= _index; i < num_chats-1; i++) {
		chats[i] = chats[i+1];
	}
	num_chats -= 1;

	return true;
}

bool ReplyAdmin::removeChat(int* _indices, int _count) {
	
	bool hasValidIndex = false;
	
	for (int i=0; i < _count; i++) {
		if (_indices[i] >= 0 && _indices[i] < num_chats) {
			hasValidIndex = true;
		}
	}

	if (!hasValidIndex) {
		return false;
	}
	
	std::sort(_indices, _indices + _count, std::greater<int>());

	for (int i=0; i < _count; i++) {
		if ( _indices[i] >= 0 && _indices[i] <= num_chats-1) {
			for ( int j = _indices[i]; j < num_chats-1; j++) {
				chats[j] = chats[j+1];
			}
			num_chats--;
		} 

	}
			
	return true;
}

bool ReplyAdmin::removeChat(int _start, int _end) {
	if (_start >= num_chats || _end < 0 || _start > _end) {
		return false;
	}

	int esubs = _end - _start + 1; 

	if (_start < 0) _start = 0;
	if (_end >= num_chats) _end = num_chats - 1;

	if (_end < num_chats-1) {
		for ( int i=_end; i >= _start; i--) {
			for (int j=i; j < num_chats-1; j++) {
				chats[j] = chats[j+1];
			}
		}
		num_chats -= esubs;
	} else {
		num_chats = num_chats - esubs;
	} 
	return true;
}

void ReplyAdmin::printChats() {
	for (int i=0; i < num_chats; i++) {
		std::cout << i << " " << chats[i] << std::endl;
	}
}


