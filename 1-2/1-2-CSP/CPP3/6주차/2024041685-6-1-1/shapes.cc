#include "shapes.h"

double Triangle::getArea() const {
	return width * height * 0.5;
}

double Rectangle::getArea() const {
	return width * height;
}
