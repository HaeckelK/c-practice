#include <stdio.h>
#include <stdlib.h>

#include "hash_table.h"

void print_stats(hash_table table) {
    printf("Count: %d, Size: %d\n", table.count, table.size);
}


void print_key_value(hash_table *table, const char *key) {
    char *value = hash_table_get(table, key);
    if (value != NULL) {
        printf("{%s: %s}\n", key, value);
    }
}


void print_hash_table(hash_table table) {
    char **keys = hash_table_keys(table);
    for (int i = 0; i < table.count; i++) {
        print_key_value(&table, keys[i]);
    }
    free(keys);
}


int main()
{
    printf("===MY-APP===\n");
    hash_table *leo = hash_table_new();
    hash_table *albert = hash_table_new();

    print_stats(*leo);

    hash_table_insert(leo, "name", "leo");
    hash_table_insert(leo, "age", "2");
    hash_table_insert(leo, "weight", "4.5kg");
    hash_table_insert(leo, "weight", "5kg");

    print_stats(*leo);
    print_hash_table(*leo);

    hash_table_delete_table(leo);
}