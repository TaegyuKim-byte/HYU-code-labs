#ifndef __SHAPES_H__
#define __SHAPES_H__
#include <iostream>

class Shape {
protected:
	double width, height;	
public:
	Shape(double _width, double _height) : width(_width), height(_height) {}
	virtual double getArea() = 0;
};

class Triangle : public Shape {
public:
	Triangle(double _width, double _height) : Shape(_width, _height) {}
	double getArea();
};

class Rectangle : public Shape {
public:
	Rectangle(double _width, double _height) : Shape(_width, _height) {}
	double getArea();
};

#endif
