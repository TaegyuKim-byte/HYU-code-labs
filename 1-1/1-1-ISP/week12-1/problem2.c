#include <stdio.h>

void printArr1(int arr[][4], int rows, int cols) {
    int i, j;
    
    for(i=0; i<rows; i++) {
        for(j=0; j<cols; j++) {
            printf("arr{%d}{%d}: %p\n", i, j, &arr[i][j]);
        }
    }
}

void printArr2(int* arr, int len) {
    int i, j;
    
    for(i=0; i<len; i++) {
        printf("arr{%d}: %p\n", i,&arr[i]);
    }
}



int main()
{
    int i, j;
    int arr[3][4] = {0, };  //초기값 지정..?
    int* parr = &arr[0][0];
    
    printArr1(arr, 3, 4);
    printArr2(arr, 12);
    /*
    for(int i = 0; i<3; i++) {
        for(int v =0; v<4; v++) {
            printf("arr[%d][%d] = %p\n", i, v, &arr[i][v]);
        }
    }
    */
    return 0;
}
