#include <stdio.h>
#include <stdlib.h>

int global;

int add(int x, int y) {
        return x + y;
}

int main()
{
    int local;
    int* allocated = (int*) malloc(sizeof(int)); //4B(sizeof(int)만큼 할당됨
                                                 // 할당된 공간의 주소가 반환됨
                                                 // 즉 주소를 포인터로 저장해야 
                                                 // 할당된 공간을 쓸수있음
                                                 
    *allocated = add(1, 2);  //포인터가 왜 들어가지 
                             //포인터가 가리키는 주소에 3을 저장장
    
    printf("(text)address of add(): %p\n", &add); //코드에 있음
    printf("(data)address of global: %p\n", &global); //데이터 에 있음
    printf("(stack)address of local: %p\n", &local); //스택에 있음
    printf("(heap)address of allocated: %p", allocated); //포인터의 주소는 스택에
                                                    //실제 메모리는 힙에 있음
    return 0;
}
