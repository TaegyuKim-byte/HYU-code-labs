#include "shapes.h"

void Circle::setInfo(int x, int y, int r) {
	xpos = x;
	ypos = y;
	radius = r;
}

double Circle::getArea() {
	return 3.14 * radius * radius;
}

double Circle::getPerimeter() {
	return 2 * 3.14 * radius;
}

void Rectangle::setInfo(int x1, int y1, int x2, int y2) {
	xpos1 = x1;
	xpos2 = x2;
	ypos1 = y1;
	ypos2 = y2;
}

double Rectangle::getArea() {
	int width, height;
	if (xpos2 > xpos1) {
		width = xpos2 - xpos1;
	} else {
		width = xpos1 - xpos2;
	}
	
	if (ypos2 > ypos1) {
		height = ypos2 - ypos1;
	} else {
		height = ypos1 - ypos2;
	}

	return width * height;
}

double Rectangle::getPerimeter() {
	int width, height;
	if (xpos2 > xpos1) {
		width = xpos2 - xpos1;
	} else {
		width = xpos1 - xpos2;
	}

	if (ypos2 > ypos1) {
		height = ypos2 - ypos1;
	} else {
		height = ypos1 - ypos2;
	}

	return 2 * (width + height);
}
