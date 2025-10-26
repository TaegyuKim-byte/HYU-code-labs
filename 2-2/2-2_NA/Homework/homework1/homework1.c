#include <stdio.h>
#include "nr.h"

void get_eps(float *eps) {
    *eps = 1.f;
    //your implementation

    float one = 1.0f;
    //*eps += 1.0f;

    while ((one + (float)(*eps / 2.0f)) > one) {
        *eps = (float)(*eps / 2.0f);
    }
}

void get_eps1(double *eps) {
    *eps = 1.0;
    //your implementation

    double one = 1.0;
    //*eps += 1.0;

    while ((one + (double)(*eps / 2.0)) > one) {
        *eps = (double)(*eps / 2.0);
    }
}

int main() {
    int ibeta, it, irnd, ngrd, machep, negep, iexp, minexp, maxexp;
    float eps, epsneg, xmin, xmax;

    int ibeta1, it1, irnd1, ngrd1, machep1, negep1, iexp1, minexp1, maxexp1;
    double eps1, epsneg1, xmin1, xmax1;

    printf("Float:\n");

    machar(&ibeta, &it, &irnd, &ngrd, &machep, &negep, &iexp, &minexp, &maxexp,
          &eps, &epsneg, &xmin, &xmax);
    printf("Machine Accuracy (machar): \t%0.20f\n", eps);

    get_eps(&eps);
    printf("Machine Accuracy (get_eps): \t%0.20f\n", eps);

    printf("Double:\n");

    machar1(&ibeta1, &it1, &irnd1, &ngrd1, &machep1, &negep1, &iexp1, &minexp1, &maxexp1,
           &eps1, &epsneg1, &xmin1, &xmax1);
    printf("Machine Accuracy (machar1): \t%0.20lf\n", eps1);

    get_eps1(&eps1);
    printf("Machine Accuracy (get_eps1): \t%0.20lf\n", eps1);

    return 0;
}