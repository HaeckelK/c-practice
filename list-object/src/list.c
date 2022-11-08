#include <stdlib.h>
#include <stdio.h>

#include "list.h"

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

// Reverse list in place
void reverse(List *list)
{
    List *new = new_list();
    // TODO need to resize as who knows how long *list is?
    for (int i = list->length - 1; i >= 0; i--)
    {
        // Also not sure this is right
        int *item = list->items[i];
        append(new, *item);
    }

    // Also want to check this
    int **tmp_items = list->items;
    list->items = new->items;
    new->items = tmp_items;

    delete_list(new);
}

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

int *get(List *list, int index)
{
    if (index < 0 || index >= list->length)
    {
        printf("List index out of range(0:%d): %d\n", list->length - 1, index);
        exit(1);
    }
    return list->items[index];
}

void delete (List *list, int index)
{
    // TODO DRY
    if (index < 0 || index >= list->length)
    {
        printf("List index out of range(0:%d): %d\n", list->length - 1, index);
        exit(1);
    }
    // TODO at some point you might want to downsize

    // We `delete` the element by just shunting everying else down one
    for (int i = index; i < list->length - 1; i++)
    {
        list->items[i] = list->items[i + 1];
    }
    // So technically the final element is still floating around, but we won't
    // see it again as we're reducing the length
    list->length--;
}

void clear(List *list)
{
    for (int i = 0; i <= list->length - 1; i++)
    {
        free(list->items[i]);
        list->items[i] = NULL; // Is this needed?
    }
    list->length = 0;
}

void delete_list(List *list)
{
    // I haven't done anything with length and capacity because they weren't made with malloc?
    clear(list);
    free(list);
}