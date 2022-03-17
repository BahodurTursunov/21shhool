#ifndef SRC_STACK_H_
#define SRC_STACK_H_
#include "door_struct.h"
struct node {
    struct door dr;
    struct node * next;
};

struct node* init(struct door door);
struct node* push(struct node* elem, struct door door);
struct node* pop(struct node* elem);
void destroy(struct node** root);


#endif  // SRC_STACK_H_
