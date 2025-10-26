#include <stdio.h>
#include <math.h>

double bad_method(double c[], double x) {
    return c[0] + c[1]*x + c[2]*x*x + c[3]*x*x*x + c[4]*x*x*x*x;
}

//pow 함수 실행 시 내부적으로 계산량이 더 많아짐.
double worst_method(double c[], double x) {
    return c[0] + c[1]*x + c[2]*pow(x, 2.0) + c[3]*pow(x, 3.0) + c[4]*pow(x, 4.0);
}

double best_method(double c[], double x) {
    return c[0] + x*(c[1] + x*(c[2] + x*(c[3] + x*c[4])));
}

double best_method2(double c[], double x) {
    int n = 4;
    double p = c[n];

    for (int j = n - 1; j >= 0; j--) p = p * x + c[j];

    return p;
}

int main() {
    // 계수: f(x) = 1 - 3x + 2x^2 - 5x^3 + x^4
    double c[5] = {1, -3, 2, -5, 1};
    double x = 5.0;

    // 계산
    double bad = bad_method(c, x);
    double worst = worst_method(c, x);
    double best = best_method(c, x);
    double best2 = best_method2(c, x);

    // Horner’s result를 참값으로 간주 (이론적으로 가장 안정적)
    double true_val = best;

    // 상대오차 계산
    double err_bad = fabs((bad - true_val) / true_val);
    double err_worst = fabs((worst - true_val) / true_val);

    // 출력
    printf("=== Polynomial Evaluation Comparison ===\n");
    printf("f(x) = 1 - 3x + 2x^2 - 5x^3 + x^4 at x = %.2f\n\n", x);
    printf("[Bad Method]   Result = %.10lf   Rel.Error = %.10e\n", bad, err_bad);
    printf("[Worst Method] Result = %.10lf   Rel.Error = %.10e\n", worst, err_worst);
    printf("[Best (Horner)]Result = %.10lf   Rel.Error = 0 (Reference)\n", best);
    printf("[Best2 (Horner)]Result = %.10lf   Rel.Error = 0 (Reference)\n", best2);

    return 0;
}
