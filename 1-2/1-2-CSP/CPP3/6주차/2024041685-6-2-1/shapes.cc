#include "shapes.h"
#include <iostream>
#include <cmath>
using namespace std;

static char** init(char** matrix, const size_t row, const size_t col) { //row:width, col:height
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			matrix[i][j] = '.';
		}
	}
	return matrix;
}

static char** auto_alloc(const size_t row, const size_t col) {
	char** matrix = new char* [row];
	for (int i = 0; i < row; i++) matrix[i] = new char[col];
	matrix = init(matrix, row, col);
	return matrix;
}

static void auto_delete(char** matrix, const size_t row, const size_t col) {
	for (int i = 0; i < row; i++) delete[] matrix[i];
	delete[] matrix;
}

void Canvas::Print() const {
	cout << " ";
	for (int i = 0; i < this->col; i++) cout << (i % 10); // col: index of col, row: index of row
	cout << endl;

	for (int i = 0; i < this->row; i++) {
		cout << (i % 10);
		for (int j = 0; j < this->col; j++) cout << this->canvas[i][j];
		cout << endl;
	}
}

void Canvas::Clear() {
	this->canvas = init(this->canvas, this->row, this->col);
}

Canvas::Canvas(const size_t row, const size_t col) : row(row), col(col) {
	canvas = auto_alloc(row, col);
}

Canvas::~Canvas() {
	auto_delete(canvas, row, col);
}

Shape::Shape(const size_t row, const size_t col, const char brush)
	: row(row), col(col), brush(brush) {}

void Canvas::Resize(const size_t newRow, const size_t newCol) {
	char** newCanvas = auto_alloc(newRow, newCol);

	for (size_t i = 0; i < std::min(row, newRow); i++) {
		for (size_t j = 0; j < std::min(col, newCol); j++) {
			newCanvas[i][j] = canvas[i][j];
		}
	}
	
	for (size_t i = row; i < newRow; i++) {
		for (size_t j = 0; j < newCol; j++) {
			newCanvas[i][j] = '.';
		}
	}

	for (size_t i = 0; i < newRow; i++) {
		for (size_t j = col; j < newCol; j++) {
			newCanvas[i][j] = '.';
		}
	}

	auto_delete(canvas, row, col);
	canvas = newCanvas;
	row = newRow;
	col = newCol;
}

bool Canvas::DrawPixel(int y, int x, const char brush) {
	if (x >= 0 && x < this->col && y >= 0 && y < this->row) {
		canvas[y][x] = brush;
		return true;
	}
	return false;
}

void Rectangle::Draw(Canvas* canvas) const {
	for (size_t i = 0; i < height; i++) {
		for (size_t j = 0; j < width; j++) {
			canvas->DrawPixel(topleftRow + i, topleftCol + j, brush);
		}
	}
}

void Rectangle::printInfo() const {
	cout << "rect " << topleftRow << " " << topleftCol << " " << width << " " << height << " " << brush << endl;
}

void UpTriangle::Draw(Canvas* canvas) const {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j <= i; j++) {
			canvas->DrawPixel(vertexRow + i, vertexCol + j, brush);
			canvas->DrawPixel(vertexRow + i, vertexCol - j, brush);
		}
	}
}

void UpTriangle::printInfo() const {
	cout << "tri_up " << vertexRow << " " << vertexCol << " " << height << " " << brush << endl;
}

void DownTriangle::Draw(Canvas* canvas) const {
	for (int i = 0; -i < height; i--) {
		for (int j = 0; j <= -i; j++) {
			canvas->DrawPixel(vertexRow + i, vertexCol + j, brush);
			canvas->DrawPixel(vertexRow + i, vertexCol - j, brush);
		}
	}
}

void DownTriangle::printInfo() const {
	cout << "tri_down " << vertexRow << " " << vertexCol << " " << height << " " << brush << endl;
}

void Diamond::Draw(Canvas* canvas) const {
	for (int i = 0; i < (col+1)/2; i++) {
		for (int j = 0; j < (row+1)/2; j++) {
			if (i + j <= dist) {
				canvas->DrawPixel((vertexRow + dist) + i, vertexCol + j, brush);
				canvas->DrawPixel((vertexRow + dist) - i, vertexCol + j, brush);
				canvas->DrawPixel((vertexRow + dist) + i, vertexCol - j, brush);
				canvas->DrawPixel((vertexRow + dist) - i, vertexCol - j, brush);
			}
		}
	}
}

void Diamond::printInfo() const {
	cout << "diamond " << vertexRow << " " << vertexCol << " " << dist << " " << brush << endl;
}

Shape::Shape() : row(0), col(0), brush(brush) {}
