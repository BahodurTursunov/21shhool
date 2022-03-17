#include "door_struct.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
char* test_add();
char* test_rm();

int main() {
    printf("RESULT - %s\n", test_add());
    printf("RESULT - %s", test_rm());

    return 0;
}

char* test_add() {
    struct node *first, *cur, *last, *tmp;
    struct door d1 = {1, 0}, d2 = {2, 0}, d3 = {3, 0};
    int flag = 1;
    cur = init(d1);
    first = cur;
    last = first;
    cur = add_door(cur, d2);
    last->next = cur;
    last = cur;
    cur = add_door(cur, d3);
    last->next = cur;
    last = cur;

    tmp = first;
    tmp = tmp->next;
    if (!(tmp->dr.id == d2.id)) {
        flag = 0;
    }
    tmp = tmp->next;
    if (!(tmp->dr.id == d3.id))
        flag = 0;
    tmp = tmp->next;
    if (!(tmp == NULL)) {
        flag = 0;
    }
    remove_door(last, &first);
    char *suc = "SUCCESS", *fail = "FAIL", *res;
    destroy(&first);
    if (flag == 1)
        res = suc;
    else
       res = fail;
    return res;
}

char* test_rm() {
    struct node *first, *cur, *last;
    struct door d1 = {1, 0}, d2 = {2, 0}, d3 = {3, 0};
    int flag = 1;
    cur = init(d1);
    first = cur;
    last = first;
    cur = add_door(cur, d2);
    last->next = cur;
    last = cur;
    cur = add_door(cur, d3);
    last->next = cur;
    last = cur;
    find_door(3, cur);
    struct node *resu = remove_door(last, &first);
    if (!(resu->dr.id == d2.id)) {
        flag = 0;
    }
    resu = remove_door(first->next, &first);
    if (!(resu->dr.id == d1.id))
        flag = 0;
    char *suc = "SUCCESS", *fail = "FAIL", *res;
    destroy(&first);
    if (flag == 1)
        res = suc;
    else
       res = fail;
    return res;
}
