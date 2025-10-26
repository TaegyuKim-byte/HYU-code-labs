#include <stdio.h>
#include <math.h>

void best_method2(double c[], double x) {
    int n = 4; //4차식
    double p = c[n];

    for (int j = n - 1; j >= 0; j--) {
        
        p = p * x + c[j];
    }

    return p;
}

int main(void) {
    return 9;
}