#include <stdlib.h>
#include <stdio.h>
#include "stack.h"
#include "door_struct.h"

char * push_test(struct node** rot, struct door door, int id) {
    struct node *root = *rot;
    struct node *result = push(root, door);
    return result -> dr.id == id ? "SUCCESS" : "FAIL";
}

char * pop_test(struct node *elem, int id) {
    struct node *result = pop(elem);
    return result -> dr.id == id ? "SUCCESS" : "FAIL";
}

void output(struct node * root) {
    struct node * aux = root;
    while (aux -> next != NULL) {
        printf("- DOOR: %d | STATUS: %d\n", aux ->dr.id, aux ->dr.status);
        aux = aux -> next;
    }
}

int main() {
    struct door first = {0, 0};
    struct door second = {1, 0};
    struct node *root = init(first);
    struct node* nw = push(root, second);
    

    //output(nw);
    push_test(&nw, second, 1);
    pop_test(nw, 1);
    destroy(&nw);
    return 0;
}




