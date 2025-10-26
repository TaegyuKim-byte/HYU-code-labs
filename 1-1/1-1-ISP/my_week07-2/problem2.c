#include <stdio.h>

int main()
{
    float num1, frac;
    int inte;
    
    printf("Enter your real number: ");
    scanf("%f", &num1);
    
    inte = (int)num1;
    
    frac = num1 - (float)inte;
    
    printf("Integer: %d, Fraction: %f", inte, frac);

    return 0;
}
