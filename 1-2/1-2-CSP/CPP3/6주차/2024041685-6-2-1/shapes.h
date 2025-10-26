#ifndef __SHAPES_H__
#define __SHAPES_H__

#include <cstddef>

class Canvas{
	public:
		Canvas(const size_t row, const size_t col);
		~Canvas();

		void Resize(const size_t row, const size_t col);
		bool DrawPixel(const int col, const int row, const char brush);
		void Print() const;
		void Clear();

	private:
		size_t row, col;
		char **canvas;
};

class Shape{
	public:
		Shape();
		Shape(const size_t row, const size_t col, const char brush); //row: row size, col: col size.

		virtual void Draw(Canvas* canvas) const = 0;
		virtual void printInfo() const = 0;
	
	protected:
		size_t col,row;
		char brush;
};

class Rectangle : public Shape {
	public:
		Rectangle(int topleftRow, int topleftCol, const size_t width, const size_t height, char brush) //tlR : index of row, tlC: index of col
			: Shape(height, width, brush), topleftRow(topleftRow), topleftCol(topleftCol), width(width), height(height) {}

		void Draw(Canvas* canvas) const override;
		void printInfo() const override;

	private:
		int topleftRow, topleftCol;
		size_t width, height;

};

class UpTriangle : public Shape {
	public:
		UpTriangle(const int vertexRow, const int vertexCol, const size_t height, char brush) //vR: index of row, vC: index of col.
			: Shape(height, 2*height-1, brush), vertexRow(vertexRow), vertexCol(vertexCol), height(height) {}

		void Draw(Canvas* canvas) const override;
		void printInfo() const override;

	private:
		int vertexRow, vertexCol;
		size_t height;
};

class DownTriangle : public Shape {
	public:
		DownTriangle(const int vertexRow, const int vertexCol, const size_t height, char brush)
			: Shape(height, 2*height-1, brush), vertexRow(vertexRow), vertexCol(vertexCol), height(height) {}
		
		void Draw(Canvas* canvas) const override;
		void printInfo() const override;
	
	private:
		int vertexRow, vertexCol;
		size_t height;
};

class Diamond : public Shape {
	public: 
		Diamond(const int vertexRow, const int vertexCol, const size_t dist, char brush) 
			: Shape(2*dist+1, 2*dist+1, brush), vertexRow(vertexRow), vertexCol(vertexCol), dist(dist) {}

		void Draw(Canvas* canvas) const override;
		void printInfo() const override;

	private:
		int vertexRow, vertexCol;
		size_t dist;
};

#endif

