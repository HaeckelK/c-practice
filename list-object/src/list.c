#include <stdlib.h>
#include <stdio.h>

#include "list.h"

List *new_list()
{
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

void append(List *list, int value)
{
    // TODO implement resize
    if (list->length >= list->capacity)
    {
        printf("List full!\n");
        exit(1);
    }

    // This gives the right output but I'm pretty sure it's garbage
    int *store = malloc(sizeof(int));

    // TODO error handling on malloc
    // TODO free on delete

    *store = value;
    list->items[list->length] = store;
    list->length++;
}

int *get(List *list, int index)
{
    if (index < 0 || index >= list->length)
    {
        printf("List index out of range(0:%d): %d\n", list->length - 1, index);
        exit(1);
    }
    return list->items[index];
}