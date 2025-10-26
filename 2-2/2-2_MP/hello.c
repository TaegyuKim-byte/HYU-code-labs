#include <stdio.h>
int add(int a, int b) { return a + b; }
int main(void) {
    int x = 3, y = 5;
    int z = add(x, y);
    printf("%d\n", z);
    return 0;
}
