#include "door_struct.h"
#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

struct node* init(struct door door) {
    struct node *first;
    first = malloc(1* sizeof(struct node));
    first->dr.id = door.id;
    first->dr.status = door.status;
    first->next = NULL;
    return first;
}

struct node* push(struct node* elem, struct door door) {
    struct node *next;
    next = malloc(sizeof(struct node));
    next->dr.id = door.id;
    next->dr.status = door.status;
    next->next = elem;
    return next;
}

struct node* pop(struct node* elem) {
    struct node *tmp = elem->next;
    free(elem);
    return tmp;
}

void destroy(struct node** root) {
struct node* p = *root;
    while (p != NULL) {
       struct node* tmp;
       tmp = p;
       p = p->next;
       free(tmp);
    }
}
