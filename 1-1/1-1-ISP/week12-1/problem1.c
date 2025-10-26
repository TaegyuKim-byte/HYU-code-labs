#include <stdio.h>

int main()
{   
    int arr[3][4] = {0, };  //초기값 지정..?
    
    for(int i = 0; i<3; i++) {
        for(int v =0; v<4; v++) {
            printf("arr[%d][%d] = %p\n", i, v, &arr[i][v]);
        }
    }
    
    return 0;
}
