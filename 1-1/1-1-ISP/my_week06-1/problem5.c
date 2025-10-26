/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    int num, rem;
    
    printf("Enter your numbers: ");
    scanf("%d", &num);
    rem = num % 2;
    
    if (rem == 1) {
        printf("Your number is odd");
    }
    else {
        printf("Your number is even");
    }
    
    
    return 0;
}
