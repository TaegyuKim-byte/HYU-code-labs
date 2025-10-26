#include <iostream>
#include <string>
#include "zebra.h"

using namespace std;

int main(void) {
	
	Zebra** zebra_arr = new Zebra*[10];
	int i,j;

	for (i=0; i<10; i++) {
		
		string _name;		
		int _age, _numStripes;

		std::cin >> _name;
		
		if (_name == "0") {
			break;
		}

		std::cin >> _age >> _numStripes;
		
		zebra_arr[i] = new Zebra(_name, _age, _numStripes);
	}

	for (j=0; j<i; j++) {
		zebra_arr[j]->printZebra();
	}
	
	delete[] zebra_arr;

	return 0;
}	
