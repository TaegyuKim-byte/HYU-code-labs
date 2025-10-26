/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    int i, j;
    i = 0;
    j = 0;
    printf("%d\n", i++); //i를 먼저 초기값 0으로 출력 후 
                         //i에 1이 더해짐 
    j = ++i; // 출력 전에 1이 또 더해져 2가 되고 그 값이 출력됨 
    printf("%d\n", j);


    return 0;
}
