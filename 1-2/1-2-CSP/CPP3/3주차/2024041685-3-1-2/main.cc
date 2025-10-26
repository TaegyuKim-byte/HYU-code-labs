#include <iostream>
#include <sstream>
#include "shapes.h"

int main() {
	std::string input;
	char shapeType;

	while(true) {
		std::cout << "shape?" << std::endl;
		std::getline(std::cin, input);
		std::istringstream iss(input);

		iss >> shapeType;

		if (shapeType == 'Q') {
			break;
		}

		if (shapeType == 'C') {
			int x, y, r;

			iss >> x >> y >> r;
			Circle circle;
			circle.setInfo(x, y, r);
			std::cout << "area: " << circle.getArea() << ", perimeter: " << circle.getPerimeter() << std::endl;
		} else if (shapeType == 'R') {
			int x1, y1, x2, y2;
			iss >> x1 >> y1 >> x2 >> y2;
			Rectangle rectangle;
			rectangle.setInfo(x1, y1, x2, y2);
			std::cout << "area: " << rectangle.getArea() << ", perimeter: " << rectangle.getPerimeter() << std::endl;
		}
	}
	return 0;
}

