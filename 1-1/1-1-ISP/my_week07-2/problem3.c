#include <stdio.h>

int main()
{
    float Cel;
    int Fah;
    
    printf("Enter the temperature in degrees Celsius: ");
    scanf("%f", &Cel);
    
    Fah = ((1.8)*Cel)+32;
    
    printf("The temperature is %d degrees Fahrenheit.\n", Fah);

    return 0;
}
