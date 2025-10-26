/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    char a = 0x48616E79616E6700UL / 0x0100000000000000;
    char b = 0x48616E79616E6700UL / 0x0001000000000000;
    char c = 0x48616E79616E6700UL / 0x0000010000000000;
    char d = 0x48616E79616E6700UL / 0x0000000100000000;
    char e = 0x48616E79616E6700UL / 0x0000000001000000;
    char f = 0x48616E79616E6700UL / 0x0000000000010000;
    char g = 0x48616E79616E6700UL / 0x0000000000000100;
    char h = 0x48616E79616E6700UL / 0x0000000000000001;
    
    printf("%c", a);
    printf("%c", b-32);
    printf("%c", c-32);
    printf("%c", d-32);
    printf("%c", e-32);
    printf("%c", f-32);
    printf("%c", g-32);
    printf("%c", h-32);

    return 0;
}
