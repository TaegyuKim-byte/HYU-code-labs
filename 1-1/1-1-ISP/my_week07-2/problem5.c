#include <stdio.h>

int main()
{
    int num1, num2, num3;
    unsigned char divi;
    
    printf("Enter two numbers to add: ");
    scanf("%d %d", &num1, &num2);
    
    num3 = num1 + num2;
    
    printf("  ");
    
    for(int i=0, divi=128/*2의 7승*/; i<8; divi /= 2, i++) {
        if (((num1 / divi)%2) == 1) {
            printf("1");
        }
        else {
            printf("0");
        }
    }
    
    printf("\n");
    printf("+ ");
    
    for(int i=0, divi=128/*2의 7승*/; i<8; divi /= 2, i++) {
        if (((num2 / divi)%2) == 1) {
            printf("1");
        }
        else {
            printf("0");
        }
    }
    
    printf("\n");
    printf("__________\n= ");
    
    for(int i=0, divi=128/*2의 7승*/; i<8; divi /= 2, i++) {
        if (((num3 / divi)%2) == 1) {
            printf("1");
        }
        else {
            printf("0");
        }
    }
    
    printf("\n");
    
    return 0;
}
