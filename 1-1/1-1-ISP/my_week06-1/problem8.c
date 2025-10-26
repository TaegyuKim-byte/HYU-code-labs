/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    int num, fac=0;
    
    printf("Enter your number: ");
    scanf("%d", &num);
    
    switch (num) {
        case 2:
            printf("Your number is a prime number!");
            break;
        case 3:
            printf("Your number is a prime number!");
            break;
        case 5:
            printf("Your number is a prime number!");
            break;
        case 7:
            printf("Your number is a prime number!");
            break;
        default : {
            printf("Your number is not a prime number!");
            break;
        }
        
    }
    return 0;
}
