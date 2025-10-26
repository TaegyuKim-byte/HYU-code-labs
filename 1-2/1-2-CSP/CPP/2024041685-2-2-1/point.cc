#include <iostream>

typedef struct{
	int xpos;
	int ypos;
} Point;

Point getScalePoint(Point* p, int s) {
	p->xpos = p->xpos * s;
	p->ypos = p->ypos * s;
	return *p;
}

void swapPoints(Point* p1, Point* p2) {
	Point imp;
	imp = *p1;
	*p1 = *p2;
	*p2 = imp;
}

int main(void) {
	int scale1, scale2;
	Point pos1, pos2;

	std::cin >> pos1.xpos >> pos1.ypos >> scale1;
	std::cin >> pos2.xpos >> pos2.ypos >> scale2;
	
	std::cout << "Calling getScalePoint() for (" << pos1.xpos << "," << pos1.ypos << ")\n";
	pos1 = getScalePoint(&pos1, scale1);

	std::cout << "Calling getScalePoint() for (" << pos2.xpos << "," << pos2.ypos << ")\n";
	pos2 = getScalePoint(&pos2, scale2);

	std::cout << "Calling swapPoints()\n";
	swapPoints(&pos1, &pos2);

	std::cout << "P1 :" << pos1.xpos << " " << pos1.ypos << "\n";
	std::cout << "P2 :" << pos2.xpos << " " << pos2.ypos << "\n";

	return 0;


}
