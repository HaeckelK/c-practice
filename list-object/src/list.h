#ifndef LIST_H
#define LIST_H

typedef struct
{
    int capacity; // The amount of memory available for elements
    int length;   // The number of actual elements stored in the array
    int **items;  // Array of integers into which the elements will be stored
} List;

List *new_list();

void append(List *list, int value);

// TODO should this be a pointer? I think yes because how else can I edit the item?
int *get(List *list, int index);

// TODO rename to delete_item?
void delete (List *list, int index);

void reverse(List *list);

void delete_list(List *list);
void clear(List *list);

#endif