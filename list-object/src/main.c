#include <stdio.h>

#include "list.h"

int main() {
    printf("Example of using List\n");

    List *list = new_list();

    for (int i = 0; i < 4; i++) {
        append(list, i * i);
    }

    for (int i = 0; i < list->capacity; i++) {
        int *value = list->items[i];
        if (value == NULL) {
            continue;
        }
        printf("%d: %d\n", i, *value);
    }

    return 0;
}