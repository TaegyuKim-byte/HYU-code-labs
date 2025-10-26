#include <stdio.h>
#include <stdlib.h>

struct course {
    char code[8];
    int ID;
    char name[32];
};


int main() {
    char cmd;
    int loop =1;
    struct course courses[5] = {{"", 0, ""},};
    
    int idx = 0;
    while (loop) {
        printf("r: registration, q: quit\n");
        scanf("%c", &cmd);
        switch (cmd) {
            case 'r':
                printf("Course code: ");
                scanf("%s", courses[idx].code);
                printf("Course ID: ");
                scanf("%d", &courses[idx].ID);
                printf("Course name: ");
                scanf("%s", courses[idx].name);
                idx++;
                break;
            case 'q':
                loop = 0;
                break;
        }
    }
    
    for (int i=0; i<sizeof(courses)/sizeof(courses[0]); i++) {
        if (courses[i].ID) {
            printf("[%d]: %s, %d, %s\n", i+1, courses[i].code, courses[i].ID, courses[i].name);
        }
    }
    
    printf("Total sizeL %lu\n", sizeof(courses));
    
    return 0;
    
}