#ifndef __SHAPES_H__
#define __SHAPES_H__

class Shape{
	public:
		Shape(double width, double height) : width(width), height(height) {} 
		
		virtual double getArea() const = 0;

	protected:
		double width, height;
};

class Triangle : public Shape {
    public: 
		Triangle(double width, double height) : Shape(width, height) {}

		double getArea() const override;
	
};

class Rectangle : public Shape {
	public:
		Rectangle(double width, double height) : Shape(width, height) {}
		
		double getArea() const override;

};

#endif
