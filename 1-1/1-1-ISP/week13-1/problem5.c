#include <stdio.h>
#include <stdlib.h>

struct course {
    char code[8];
    int ID;
    char name[32];
    struct course* next;
};


int main() {
    char cmd;
    int i, loop =1;
    struct course* courses = NULL;
    struct course *c, *new, *last;
    size_t allocated = 0;
    
    int idx = 0;
    while (loop) {
        printf("r: registration, q: quit\n");
        scanf(" %c", &cmd);
        switch (cmd) {
            case 'r':
                new = (struct course*) malloc(sizeof(struct course));
                printf("Course code: ");
                scanf("%s",&new->code[0]);
                printf("Course ID: ");
                scanf("%d", &new->ID);
                printf("Course name: ");
                scanf("%s", &new->name[0]);
                new->next = NULL;
                
                if (courses == NULL) {
                    courses = new;
                } else {
                    last->next = new;
                }
                last = new;
                break;
            case 'q':
                loop = 0;
                break;
        }
    }
    
    i=0;
    c = courses;
    do {
        if (c==NULL)
            break;
        allocated += sizeof(struct course);
        printf("course[%d]: %s, %d, %s\n", i+1, c->code,
            c->ID, c->name);
        c = c->next;
        i++;
    } while (1);
    
    printf("Total size: %lu\n", sizeof(courses) + allocated);
    
    
    return 0;
    
}