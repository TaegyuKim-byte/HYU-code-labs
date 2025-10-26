#include <stdio.h>

int main()
{
    int j;
    char i,v;
    
    printf("Enter your lower case: ");
    scanf("%c", &v);
    
    j = ("%d", v);
    i = j -32;
    
    printf("Your Uppercase about %c is %c", v, i);
    return 0;
}