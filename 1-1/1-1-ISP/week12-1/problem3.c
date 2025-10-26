#include <stdio.h>
#include <string.h>

int main()
{   
    int i, size1, size2;
    char names1[][16] = {"Alice", "Bob", "Charlie", "David", "Ethan"};
    char* names2[] = {"Alice", "Bob", "Charlie", "David", "Ethan"};
    
    size1= sizeof(names1);
    
    for (i=0; i<sizeof(names1)/sizeof(names1[0]); i++) {
        printf("names{%d}: %p\n", i, &names1[i]);
        
    }
    
    size2= sizeof(names2);
    
    printf("\n");
    
    for (i=0; i<sizeof(names2)/sizeof(names2[0]); i++) {
        printf("names[%d}: %p\n", i, &names2[i]);
        size2 += (strlen(names2[i]) +1);
    }
    
    printf("size1: %d, size2: %d\n", size1, size2);
    
    return 0;
}
