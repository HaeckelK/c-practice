#include <stdio.h>
#include <assert.h>

#include "list.h"

void print_list(List *list) {
    printf("Printing List\n");
    for (int i = 0; i < list->length; i++)
    {
        int *value = get(list, i);
        printf("%d: %d\n", i, *value);
    }
}

int main()
{
    printf("Example of using List\n");

    List *list = new_list();

    int initial_range = 3;

    for (int i = 0; i < initial_range; i++)
    {
        append(list, i * i);
    }
    assert(list->length == initial_range);

    // TODO this also works but I can't help but feel I'm misunderstanding proper
    // pointer use
    int *element = get(list, 1);
    *element = 100;

    print_list(list);
    reverse(list);
    print_list(list);

    delete(list, 0);

    // TODO assert here on length and capacity
    assert(list->length == 2);

    append(list, 123);

    print_list(list);

    clear(list);
    print_list(list);

    return 0;
}