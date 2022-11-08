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

void test_init_values() {
    List *list = new_list();
    assert(list->length == 0);
}

// Show that length increments on each added item
void test_append_length_increment(){
    List *list = new_list();
    // TODO this is constrained by capacity size
    for (int i = 0; i < 3; i++){
        append(list, 0);
        assert(list->length == i + 1);
    }
}

void test_append_values() {
    List *list = new_list();

    int target[] = {1,7,100};

    append(list, 1);
    append(list, 7);
    append(list, 100);

    for (int i = 0; i < 3; i++) {
        // Relying on internal structure otherwise we'd be testing get as well
        int *item = list->items[i];
        assert(*item == target[i]);
    }
}

void test_delete(){
    List *list = new_list();
    append(list, 1);
    append(list, 2);
    append(list, 3);

    delete_list(list);
    // TODO what to asser?
}

int main()
{
    printf("Example of using List\n");

    test_init_values();
    test_append_length_increment();
    test_append_values();
    test_delete();

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