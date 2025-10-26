#include "shapes.h"
#include <iostream>

double Triangle::getArea() {
	return 0.5 * width * height;
}

double Rectangle::getArea() {
	return width * height;
}
