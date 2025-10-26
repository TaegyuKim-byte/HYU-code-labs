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
    struct course* courses[5] = {NULL, };
    struct course* c;
    size_t allocated = 0;
    
    int idx = 0;
    while (loop) {
        printf("r: registration, q: quit\n");
        scanf(" %c", &cmd);
        switch (cmd) {
            case 'r':
                c = (struct course*) malloc(sizeof(struct course));
                printf("Course code: ");
                scanf("%s",&c->code[0]);
                printf("Course ID: ");
                scanf("%d", &c->ID);
                printf("Course name: ");
                scanf("%s", &c->name[0]);
                courses[idx] = c;
                idx++;
                break;
            case 'q':
                loop = 0;
                break;
        }
    }
    
    for (int i=0; i<sizeof(courses)/sizeof(courses[0]); i++) {
        if (courses[i].ID) {
            allocated += sizeof(struct course);
            printf("course[%d]: %s, %d, %s\n", i+1, courses[i]->code,
            courses[i]->ID, courses[i]->name);
        }
    }
    
    printf("Total size: %lu\n", sizeof(courses) + allocated);
    
    
    return 0;
    
}