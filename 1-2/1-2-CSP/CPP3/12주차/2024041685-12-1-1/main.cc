#include "my_container.h"
#include <iostream>

int main() {
	int numofint, numofrealnum, numofwords;

	std::cin >> numofint;
	MyContainer<int> cont_int(numofint);
	std::cin >> cont_int;
	std::cout << cont_int;

	std::cin >> numofrealnum;
	MyContainer<double> cont_dou(numofrealnum);
	std::cin >> cont_dou;
	std::cout << cont_dou;

	std::cin >> numofwords;
	MyContainer<std::string> cont_str(numofwords);
	std::cin >> cont_str;
	std::cout << cont_str;

	return 0;
}