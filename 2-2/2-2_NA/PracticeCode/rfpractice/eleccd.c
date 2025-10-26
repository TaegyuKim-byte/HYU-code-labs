#include <stdio.h>
#include <math.h>

double fr(double r) {
    if (r <= 0 || r >= 400) {
        printf("Incorrect range!\n");
        return 0;
    }
    return exp(-0.005 * r) * cos(floor(0.05 * sqrt(2000 - 0.01 * r * r))) - 0.01;
}

int main(void) {

    //bisection
    //N-R
    //secant
    //Line interpolation
    return 0;
}