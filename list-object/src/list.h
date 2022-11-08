#ifndef LIST_H
#define LIST_H

typedef struct
{
    int capacity; // The amount of memory available for elements
    int length;  // The number of actual elements stored in the array
    int **items; // Array of integers into which the elements will be stored
} List;

List *new_list();

void append(List *list, int value);

#endif