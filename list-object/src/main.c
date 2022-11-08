#include <stdio.h>

#include "list.h"

int main() {
    printf("Example of using List\n");

    List *list = new_list();

    for (int i = 0; i < 3; i++) {
        append(list, i * i);
    }

    // TODO this also works but I can't help but feel I'm misunderstanding proper 
    // pointer use
    int *element = get(list, 10);
    *element = 100;

    for (int i = 0; i < list->length; i++) {
        int *value = get(list, i);
        printf("%d: %d\n", i, *value);
    }

    return 0;
}