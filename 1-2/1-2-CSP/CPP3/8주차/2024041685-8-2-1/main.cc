#include "shapes.h"
#include <iostream>
#include <vector>

int main(void) {
	double Width, Height, TriArea, RecArea;

	std::cin >> Width >> Height;

	std::vector<Shape*> arr;
	std::vector<Shape*>::iterator iter = arr.begin();
	arr.push_back(new Triangle(Width, Height));

	std::cin >> Width >> Height;

	arr.push_back(new Rectangle(Width, Height));

	for (auto iter = arr.begin(); iter != arr.end(); ++iter) {
		std::cout << (*iter)->getArea() << std::endl;
	}

	for (auto iter = arr.begin(); iter != arr.end(); ++iter) {
		delete* iter;
	}

	return 0;
}
