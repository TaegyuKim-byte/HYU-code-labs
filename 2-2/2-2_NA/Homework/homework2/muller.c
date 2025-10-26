#include <stdio.h>
#include <math.h>

extern int muller_iter;

float sgn(float x) {
    return (x > 0) ? 1.0f : ((x < 0) ? -1.0f : 0.0f);
}

/*
float muller(float (*func)(float), float x0, float x1, float x2, float xacc) {
    muller_iter++;
    
    float x3, a, b, c;

    c = func(x2);

    b = ((x0 - x2) * (func(x1) - func(x2)) - (x1 - x2) * (x1 - x2) * (func(x0) - func(x2)))
        / ((x0 - x2) * (x1 - x2) * (x0 - x1));

    a = ((x1 - x2) * (func(x0) - func(x2)) - (x0 - x2) * (func(x1) - func(x2)))
        / ((x0 - x2) * (x1 - x2) * (x0 - x1));

    x3 = x2 - (2.0f * c) / (b + sgn(b) * sqrt(b * b - 4.0f * a * c));

    if (fabs(x3 - x2) < xacc) {
        return x3;
    } else {
        return muller(func, x1, x2, x3, xacc);
    }
}
*/

float muller(float (*func)(float), float x0, float x1, float x2, float xacc) {
    muller_iter++;

    //변경점: 함숫값 미리 계산
    float f0 = func(x0);
    float f1 = func(x1);
    float f2 = func(x2);

    float a, b, c, x3;
    c = f2;

    b = ((x0 - x2) * (f1 - f2) - (x1 - x2) * (f0 - f2))
        / ((x0 - x2) * (x1 - x2) * (x0 - x1));

    a = ((f0 - f2) - b * (x0 - x2)) / ((x0 - x2) * (x0 - x1));

    float disc = b * b - 4.0f * a * c;
    if (disc < 0.0f) {
        return x2;
    }

    x3 = x2 - (2.0f * c) / (b + sgn(b) * sqrtf(disc));

    // 종료 조건 변경: x 변화량 또는 함수값이 충분히 작으면 종료
    if (fabsf(x3 - x2) < xacc || fabsf(func(x3)) < xacc) {
        return x3;
    } else {
        return muller(func, x1, x2, x3, xacc);
    }
}
