#include <stdio.h>

int main()
{
    for(int i=33; i<=127; i++) {
        printf("%d  %X  %c\n", i, (char)i, (char)i);
    }

    return 0;
}
