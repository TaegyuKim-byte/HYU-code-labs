#ifndef __SHAPES_H__
#define __SHAPES_H__

#include <cmath>
#include <cstddef>

class Canvas {
	public:
		Canvas(const size_t row, const size_t col);
		~Canvas();

		bool DrawPixel(const int x, const int y, const char brush);
		void Print() const;
		void Clear();

	private:
		size_t row, col;
		char **canvas;
};

class Shape {
	public:
		Shape();
		Shape(const size_t x, const size_t y, const char brush);

		virtual double GetArea() const = 0;
		virtual int GetPerimeter() const =0;
		virtual void Draw(Canvas* canvas) const = 0;
		virtual ~Shape() {};

	protected:
		size_t x, y;
		char brush;
};

class Square : public Shape {
	public:
		Square() {};
		Square(size_t x, size_t y, size_t size, char brush);
		double GetArea() const override;
		int GetPerimeter() const override;
		void Draw(Canvas* canvas) const override;
	
	private:
		size_t size;
};

class Rectangle : public Shape {
	public:
		Rectangle() {};
		Rectangle(size_t x, size_t y, size_t width, size_t height, char brush);
		double GetArea() const override;
		int GetPerimeter() const override;
		void Draw(Canvas* canvas) const override;
	
	private:
		size_t width;
		size_t height;
};

#endif
	
