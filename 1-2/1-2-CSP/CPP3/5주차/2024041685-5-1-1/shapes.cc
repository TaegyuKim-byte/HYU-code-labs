#include "shapes.h"
#include <iostream>
using namespace std;

static char **init(char **matrix, const size_t row, const size_t col) {
	for (int i=0; i<row; ++i) {
		for (int j=0; j<col; ++j) {
			matrix[i][j] = '.';
		}
	}
	return matrix;
}

static char **auto_alloc(const size_t row, const size_t col) {
	char **matrix = new char*[row];
	for (int i=0; i<row; ++i) matrix[i] = new char[col];
	matrix = init(matrix, row, col);
	return matrix;
}

static void auto_delete(char **matrix, const size_t row, const size_t col) {
	for (int i=0; i<row; ++i) delete[] matrix[i];
	delete[] matrix;
}

Shape::Shape(const size_t x, const size_t y, const char brush) : x(x), y(y), brush(brush) {}

Square::Square(size_t x, size_t y, size_t size, char brush) : Shape(x, y, brush), size(size) {}

Rectangle::Rectangle(size_t x, size_t y, size_t width, size_t height, char brush) : Shape(x, y, brush), width(width), height(height) {}

Canvas::Canvas(const size_t row, const size_t col) :row(row),col(col) {
	canvas = auto_alloc(row, col);
}

Canvas::~Canvas() {
	auto_delete(canvas, row, col);
}

void Canvas::Print() const {
	cout << " ";
	for (int i = 0; i < this->col; ++i) cout << (i);
	cout << endl;

	for (int i = 0; i < this->row; ++i) {
		cout << (i);
		for (int j=0; j<this->col; ++j) cout << this->canvas[i][j];
		cout << endl;
	}
}

void Canvas::Clear() {
	this->canvas = init(this->canvas, this->row, this->col);
}

bool Canvas::DrawPixel(const int x, const int y, const char brush) {
	if (x>=0 && x<row && y>=0 && y<col) {
		canvas[y][x] = brush;
		return true;
	}
	return false;
}

void Square::Draw(Canvas* canvas) const {
	for (size_t i = 0; i < size; ++i) {
		for (size_t j = 0; j < size; ++j) {
			if (canvas->DrawPixel(x + j, y + i, brush)) {

			}
		}
	}
}

void Rectangle::Draw(Canvas* canvas) const {
	for (size_t i = 0; i < height; i++) {
		for (size_t j = 0; j < width; j++) {
			if (canvas->DrawPixel(x + j, y + i, brush)) {

			}
		}
	}
}

double Square::GetArea() const {
	return size * size;
}

int Square::GetPerimeter() const{
	return 4 * size;
}

double Rectangle::GetArea() const {
	return width * height;
}

int Rectangle::GetPerimeter() const {
	return 2 * (width + height);
}


