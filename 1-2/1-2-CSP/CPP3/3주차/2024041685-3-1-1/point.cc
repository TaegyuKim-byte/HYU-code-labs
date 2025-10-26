#include <iostream>

typedef struct {
    int xpos;
    int ypos;
}Point;

void getShortest(const Point* points, int n, Point* minP1, Point* minP2) {
    int minDist = 2100000000;

    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (i != j) {
                int dist = (points[j].xpos - points[i].xpos) * (points[j].xpos - points[i].xpos) + (points[j].ypos - points[i].ypos) * (points[j].ypos - points[i].ypos);
                if (dist < minDist) {
                    minDist = dist;
                    *minP1 = points[i];
                    *minP2 = points[j];
                }
            }
        }
    }
}

void getLongest(const Point* points, int n, Point* maxP1, Point* maxP2) {
    int maxDist = 0;

    for (int k = n - 1; k >= 0; k--) {
        for (int h = n - 1; h >= 0; h--) {
            if (k != h) {
                int dist = (points[h].xpos - points[k].xpos) * (points[h].xpos - points[k].xpos) + (points[h].ypos - points[k].ypos) * (points[h].ypos - points[k].ypos);
                if (dist > maxDist) {
                    maxDist = dist;
                    *maxP1 = points[k];
                    *maxP2 = points[h];
                }
            }
        }
    }
}

int main(void) {
    int num;

    std::cin >> num;

    Point* points1 = new Point[num];

    for (int i = 0; i < num; i++) {
        std::cin >> points1[i].xpos >> points1[i].ypos;
    }

    Point minP1, minP2, maxP1, maxP2;

    getShortest(points1, num, &minP1, &minP2);

    getLongest(points1, num, &maxP1, &maxP2);

    std::cout << "longest: (" << maxP1.xpos << "," << maxP1.ypos << ") (" << maxP2.xpos << "," << maxP2.ypos << ")" << std::endl;

    std::cout << "shortest: (" << minP1.xpos << "," << minP1.ypos << ") (" << minP2.xpos << "," << minP2.ypos << ")" << std::endl;

    delete[] points1;

    return 0;
}