#include <iostream>
#include <string>
#include <sstream>
#include "shapes.h"

using namespace std;

int main(void) {
	size_t canvasRow, canvasCol;

	cin >> canvasCol;
	cin >> canvasRow;

	Canvas canvas(canvasRow, canvasCol);
	cin.ignore();

	string command;

	while (true) {
		getline(cin, command);

		stringstream ss(command);
		string firstToken;

		ss >> firstToken;

		if (isdigit(firstToken[0])) {
			size_t newRow, newCol;
			newRow = stoi(firstToken);
			ss >> newCol;

			canvas.~Canvas();
			new (&canvas) Canvas(newRow, newCol);
		}
		else if (firstToken == "quit") {
			break;
		}
		else {
			string shapeType = firstToken;
			if (shapeType == "rect") {
				canvas.Clear();
				size_t x, y, width, height;
				char brush;
				ss >> x >> y >> width >> height >> brush;

				Rectangle rectangle(x, y, width, height, brush);
				cout << "Area: " << rectangle.GetArea() << "\nPerimeter: " << rectangle.GetPerimeter() << endl;
				rectangle.Draw(&canvas);
				canvas.Print();
			}
			else if (shapeType == "square") {
				canvas.Clear();
				size_t x, y, size;
				char brush;
				ss >> x >> y >> size >> brush;

				Square square(x, y, size, brush);
				cout << "Area: " << square.GetArea() << "\nPerimeter: " << square.GetPerimeter() << endl;
				square.Draw(&canvas);
				canvas.Print();
			}
			else {
				cout << "Error!" << endl;
			}
		}
	}
	return 0;
}
