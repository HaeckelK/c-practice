#include <stdio.h>
#include <assert.h>

#include "list.h"

void print_list(List *list)
{
    printf("Printing List\n");
    for (int i = 0; i < list->length; i++)
    {
        int *value = get(list, i);
        printf("%d: %d\n", i, *value);
    }
}

void test_init_values()
{
    List *list = new_list();
    assert(list->length == 0);
}

// Show that length increments on each added item
void test_append_length_increment()
{
    List *list = new_list();
    // TODO this is constrained by capacity size
    for (int i = 0; i < 3; i++)
    {
        append(list, 0);
        assert(list->length == i + 1);
    }
}

void test_append_values()
{
    List *list = new_list();

    int target[] = {1, 7, 100};

    append(list, 1);
    append(list, 7);
    append(list, 100);

    for (int i = 0; i < 3; i++)
    {
        // Relying on internal structure otherwise we'd be testing get as well
        int *item = list->items[i];
        assert(*item == target[i]);
    }
}

void test_delete_list()
{
    List *list = new_list();
    append(list, 1);
    append(list, 2);
    append(list, 3);

    delete_list(list);
    // TODO what to asser?
}

void test_clear()
{
    List *list = new_list();
    append(list, 1);
    append(list, 2);

    int length = list->length;

    clear(list);

    assert(list->length == 0);

    for (int i = 0; i <= length - 1; i++)
    {
        assert(list->items[i] == NULL);
    }
}

void test_delete_length_decrement() {
    List *list = new_list();
    append(list, 10);
    append(list, 20);
    append(list, 30);

    int length = list->length;

    for (int i = 0; i < 3; i++) {
        delete(list, 0);
        assert(list->length == length - i - 1);
    }
}

void test_delete(){
    List *list = new_list();
    append(list, 10);
    append(list, 20);
    append(list, 30);

    delete(list, 1);
    assert(*(list->items[0]) == 10);
    assert(*(list->items[1]) == 30);

    delete(list, 0);
    assert(*(list->items[0]) == 30);
}

int main()
{
    printf("Example of using List\n");

    test_init_values();
    test_append_length_increment();
    test_append_values();
    test_delete_list();
    test_clear();
    test_delete_length_decrement();

    return 0;
}