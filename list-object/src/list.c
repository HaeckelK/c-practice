#include <stdlib.h>

#include "list.h"

List *new_list() {
    // dummy defualt capacity for now
    const int DEFAULT_CAPACITY = 3;
    List *list = malloc(sizeof(List));
    // TODO error handling on malloc

    int **items = malloc(DEFAULT_CAPACITY * sizeof(int));

    // TODO error handling on malloc

    list->length = 0;
    list->capacity = DEFAULT_CAPACITY;
    list->items = items;
    return list;
}