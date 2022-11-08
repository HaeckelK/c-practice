#include <stdlib.h>

#include "list.h"

List *new_list() {
    // dummy defualt capacity for now
    const int DEFAULT_CAPACITY = 3;
    List *list = malloc(sizeof(List));
    // TODO error handling on malloc
    // TODO free on delete

    int **items = malloc(DEFAULT_CAPACITY * sizeof(int));

    // TODO error handling on malloc
    // TODO free on delete

    list->length = 0;
    list->capacity = DEFAULT_CAPACITY;
    list->items = items;
    return list;
}

void append(List *list, int value) {
    // This gives the right output but I'm pretty sure it's garbage
    int *store = malloc(sizeof(int));

    // TODO error handling on malloc
    // TODO free on delete

    *store = value;
    list->items[list->length] = store;
    list->length++;   
}