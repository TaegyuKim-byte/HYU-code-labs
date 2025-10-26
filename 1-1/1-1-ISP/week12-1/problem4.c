#include <stdio.h>

int add(int x, int y) {
    return x + y;
} //add함수를 정의 



int main()
{   
    int x = 1, y = 2;
    int (*fprt)(int, int); //fprt를 정의하는 줄임 (형태가 생소)
    fprt = add;
    
    printf("fprt(1, 2): %d\n", fprt(1, 2));
    printf("add(1, 2): %d\n", add(1, 2));
    
    return 0;
}
