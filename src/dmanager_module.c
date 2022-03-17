#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "door_struct.h"

#define DOORS_COUNT 15
#define MAX_ID_SEED 10000

void initialize_doors(struct door* doors);
void sort(struct door* doors);
void close(struct door* doors);
void output(struct door* doors);

int main() {
    struct door doors[DOORS_COUNT];
    initialize_doors(doors);
    sort(doors);
    close(doors);
    output(doors);

    return 0;
}

// Doors initialization function
// ATTENTION!!!
// DO NOT CHANGE!
void initialize_doors(struct door* doors) {
    srand(time(0));

    int seed = rand() % MAX_ID_SEED;
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].id = (i + seed) % DOORS_COUNT;
        doors[i].status = rand() % 2;
    }
}


void sort(struct door* doors) {
    for (int i = 1; i < DOORS_COUNT; i++) {
        int j = i;
        while (j > 0 && doors[j].id < doors[j-1].id) {
            struct door tmp = doors[j];
            doors[j] = doors[j-1];
            doors[j-1] = tmp;
            j--;
        }
    }
}

void close(struct door* doors) {
    for (int i = 0; i < DOORS_COUNT; i++)
        doors[i].status = 0;
}

void output(struct door* doors) {
    for (int i = 0; i < DOORS_COUNT; i++) {
        if (i != DOORS_COUNT-1)
        printf("%d, %d\n", doors[i].id, doors[i].status);
        else
        printf("%d, %d", doors[i].id, doors[i].status);
    }
}
