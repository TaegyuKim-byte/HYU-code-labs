/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    int num;
    
    printf("Enter your number: ");
    scanf("%d", &num);
    
    for(int i=0; i<9; i++) {
        printf("%d * %d = %d\n", num, i+1, num*(i+1));
    }
    
    return 0;
}
