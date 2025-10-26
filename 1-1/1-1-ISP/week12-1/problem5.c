#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int add(int x, int y) {
    return x+y;
}

int sub(int x, int y) {
    return x - y;
}

int mul(int x, int y) {
    return x * y;
}

int main()
{   
    int num1, num2, op, ans, input;
    char operations[3] = {'+', '-', '*'};
    int (*fptrs[3])(int, int) = {add, sub, mul};
    srand(time(NULL));
    num1 = rand() % 100;
    num2 = rand() % 100;
    op = rand()%3;
    ans = fptrs[op](num1, num2);
    
    printf("%d %c %d = ", num1, operations[op], num2);
    scanf("%d", &input);
    
    if (ans == input) {
        printf("Pass!\n");
    }
    else {
        printf("Wrong!\n");
    }
    
    
    return 0;
}
