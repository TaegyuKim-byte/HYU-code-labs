#include <iostream>
#include <cstring>
#include <cctype>

void convert_case(char* a) {
	for (int i=0; a[i] != '\0'; i++) {
		if ((a[i] >= 65) && (a[i] <= 90)) {
			a[i] = a[i] + 32;
		}
		else if ((a[i] >= 97) && (a[i] <= 122)) {
			a[i] = a[i] -32;
		}
		else {
			std::cout << "Error: Wrong input!" << std::endl;
			exit(1);
		}
	}
}

int main(void) {
	char *str;
	int again=1;
	size_t len = 100;

	while (again) {
		str = new char[len];

		std::cin >> str;

		if (std::strcmp(str, "exit") == 0) {
			delete[] str;
			exit(0);
		}

		convert_case(str);

		std::cout << str << std::endl;

		delete[] str;
	}
	return 0;
}
