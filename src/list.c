#include <stdio.h>
#include <stdlib.h>
#include "door_struct.h"
#include "list.h"

struct node* init(struct door door) {
    struct node *nw = (struct node*)calloc(1, sizeof(struct node));
    nw->dr.id = door.id;
    nw->dr.status = door.status;
    nw->next = NULL;
    return nw;
}

struct node* add_door(struct node* elem, struct door door) {
    elem = (struct node*)calloc(1, sizeof(struct node));
    elem->dr.id = door.id;
    elem->dr.status = door.status;
    elem->next = NULL;
    return elem;
}

struct node* find_door(int door_id, struct node* root) {
    struct node *tmp = root, *find = NULL;
    while (tmp != NULL) {
        if (tmp->dr.id == door_id)
            find = tmp;
        tmp = tmp->next;
    }
    return find;
}

struct node* remove_door(struct node* elem, struct node** root) {
    struct node* tmp = *root;
    while (tmp->next != elem) {
        tmp = tmp->next;
    }
    tmp->next = elem->next;
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
