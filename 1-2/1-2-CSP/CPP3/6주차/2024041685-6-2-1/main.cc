#include <iostream>
#include <string>
#include <sstream>
#include "shapes.h"
using namespace std;

int main() {
	
	int size = 10;
	int index = 0;
	int xpos, ypos;
	int deleteIndex;
	size_t _width, _height, _dist;
	size_t canvasRowsize, canvasColsize, newRowsize, newColsize;
	char brush;
	string input, command, shape;

	Shape **shape_arr = new Shape * [size];

	cin >> canvasRowsize >> canvasColsize;

	Canvas canvas(canvasRowsize, canvasColsize);
	canvas.Print(); // 초기 캔버스 출력

	cin.ignore();
	
	while (true) {
		getline(cin, input);

		stringstream iss(input);
		iss >> command;

		if (command == "quit") {
			break;
		}
		else if (command == "add") {
			iss >> shape;
			if (shape == "rect") {
				iss >> ypos >> xpos >> _width >> _height >> brush;
				shape_arr[index] = new Rectangle(ypos, xpos, _width, _height, brush);
				shape_arr[index]->Draw(&canvas);
				index++;
			}
			else if (shape == "tri_down") {
				iss >> ypos >> xpos >> _height >> brush;
				shape_arr[index] = new DownTriangle(ypos, xpos, _height, brush);
				shape_arr[index]->Draw(&canvas);
				index++;
			}
			else if (shape == "tri_up") {
				iss >> ypos >> xpos >> _height >> brush;
				shape_arr[index] = new UpTriangle(ypos, xpos, _height, brush);
				shape_arr[index]->Draw(&canvas);
				index++;
			}
			else if (shape == "diamond") {
				iss >> ypos >> xpos >> _dist >> brush;
				shape_arr[index] = new Diamond(ypos, xpos, _dist, brush);
				shape_arr[index]->Draw(&canvas);
				index++;
			}
		}
		else if (command == "draw") {
			canvas.Print();
		}
		else if (command == "resize") {
			iss >> newRowsize >> newColsize;
			canvas.Resize(newColsize, newRowsize);
		}
		else if (command == "dump") {
			for (int i = 0; i < index; i++) {
				cout << i << " ";
				shape_arr[i]->printInfo();			
			}
		}
		else if (command == "delete") {
			iss >> deleteIndex;
			
			if (deleteIndex >= 0 && deleteIndex < index) {
				delete shape_arr[deleteIndex];

				for (int i = deleteIndex; i < index - 1; i++) {
					shape_arr[i] = shape_arr[i + 1];
				}
				shape_arr[index - 1] = nullptr;

				index--;
			}
			
			for (int i = 0; i < canvasRowsize; i++) {
				for (int j = 0; j < canvasColsize; j++) {
					canvas.DrawPixel(i, j, '.');
				}
			}
			for (int i = 0; i < index; i++) {
				shape_arr[i]->Draw(&canvas);
			}
		}
	}
	
	for (int i = 0; i < index; i++) {
		delete shape_arr[i];
	}

	delete[] shape_arr;

	return 0;
}
