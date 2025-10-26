#include <stdio.h>
#include "nr.h"

// 가능한 구간의 개수 (임의 설정)
#define N 100

//Bessel function의 도함수
void bessj0d(float x, float *f, float *df) {
    *f = bessj0(x);
    *df = -bessj1(x);
}

float another_func(float x) {
    return x*x*x - x - 1;
}

void another_funcd(float x, float *f, float *df) {
    *f = another_func(x);
    *df = 3*x*x - 1;
}

/*터미널 컴파일 명령어: 
gcc -o rtbessel homework2.c 
./NRs/ansi/recipes/zbrak.c 
./NRs/ansi/recipes/rtbis.c 
./NRs/ansi/recipes/nrutil.c 
./NRs/ansi/recipes/rtflsp.c 
./NRs/ansi/recipes/rtsec.c 
./NRs/ansi/recipes/rtnewt.c 
./NRs/ansi/recipes/rtsafe.c 
./NRs/ansi/recipes/bessj0.c 
./NRs/ansi/recipes/bessj1.c 
muller.c -I ./Nrs/ansi/other
*/

//반복 횟수 카운터 전역변수(필요시 사용)
int rtbis_iter;
int rtflsp_iter;
int rtsec_iter;
int rtnewt_iter;
int rtsafe_iter;
int muller_iter;

int main() {
    float xb1[N], xb2[N];
    int nb = 100;
    zbrak(bessj0, 1.0f, 10.0f, N, xb1, xb2, &nb);

    for (int i = 1; i <= nb; i++) {
        printf("Interval %d: [%f, %f]\n", i, xb1[i], xb2[i]);
        printf("a) Bisection: %f\n", rtbis(bessj0, xb1[i], xb2[i], 1.0e-6f));
        printf("b) Linear interpolation: %f\n", rtflsp(bessj0, xb1[i], xb2[i], 1.0e-6f));
        printf("c) Secant: %f\n", rtsec(bessj0, xb1[i], xb2[i], 1.0e-6f));
        printf("d) Newton-Raphson: %f\n", rtnewt(bessj0d, xb1[i], xb2[i], 1.0e-6f));
        printf("e) Newton with bracketing: %f\n", rtsafe(bessj0d, xb1[i], xb2[i], 1.0e-6f));

        //Muller method
        printf("f) Muller: %f\n", muller(bessj0, xb1[i], (xb1[i] + xb2[i]) / 2, xb2[i], 1.0e-6f));
        printf("\n");
    }

    //반복 횟수 출력
    printf("Iteration counts:\n");
    printf("Bisection: %d\n", rtbis_iter);
    printf("Linear interpolation: %d\n", rtflsp_iter);
    printf("Secant: %d\n", rtsec_iter);
    printf("Newton-Raphson: %d\n", rtnewt_iter);
    printf("Newton with bracketing: %d\n", rtsafe_iter);
    printf("Muller: %d\n", muller_iter);
    printf("\n");
    
    printf("another function root finding:\n");
    printf("Root of x^3 - x - 1 = 0: %f\n", rtsafe(another_funcd, 1.0f, 2.0f, 1.0e-6f));

    return 0;
}

//수정된 코드: homework2.c, muller.c, NRs/ansi/other/nr.h