#include <stdio.h>
#include <stdlib.h>

void printb(char ch) {
    // TODO: implement here...
    // 41 -> 00101001
    
    /*
    int j = 64;

    if (ch > 0) {
        printf("0");
        for (int i = 6; i >= 0; i--) {
        printf("%d", ch / j);
        
        if (ch / j == 1) {
            ch %= j;
        }
        j /= 2;
    }
    } else {
        printf("1");
        printb(ch + 128);
    }
    */

    for (int i = 7; i >= 0; i--) {
        printf("%d", (ch >> i) & 1);
    }
}

int main(int argc, char** argv) {
    char op;
    int num1, num2;

    printf("Enter the expression\n");
    printf("For unary operations, use 0 as the first number.\n");
    scanf("%d %c %d", &num1, &op, &num2);

    switch(op) { 
        case '&': {
            printf("  ");
            printb(num1);
            printf("\n%c ", op);
            printb(num2);
            printf("\n----------\n  ");
            printb(num1 & num2);
            break;
        } case '|': {
            printf("  ");
            printb(num1);
            printf("\n%c ", op);
            printb(num2);
            printf("\n----------\n  ");
            printb(num1 | num2);
            break;
        } case '^': {
            printf("  ");
            printb(num1);
            printf("\n%c ", op);
            printb(num2);
            printf("\n----------\n  ");
            printb(num1 ^ num2);
            break;
        } case '~': {
            printf("~ ");
            printb(num2);
            printf("\n----------\n  ");
            printb(~num2);
            break;
        } default: {
            break;
        }
    }
    // TODO: implement here...
    // Supported operations: & | ^ ~
    return 0;
}