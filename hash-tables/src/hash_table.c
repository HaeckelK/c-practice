#include <stdlib.h>
#include <string.h>
#include <stdio.h>  // TODO remove with debug statements

#include "hash_table.h"

const int INITIAL_SIZE = 53;
const int RESIZE_LOAD_LIMIT = 3;

static hash_table_item HT_DELETED_ITEM = {NULL, NULL};

static hash_table_item *hash_table_new_item(const char *key, const char *value)
{
    hash_table_item *item = malloc(sizeof(hash_table_item));
    item->key = strdup(key);
    item->value = strdup(value);
    return item;
}

static hash_table *hash_table_new_specify_size(int size)
{
    hash_table *table = malloc(sizeof(hash_table));
    table->count = 0;
    table->size = size;
    table->items = calloc((size_t)table->size, sizeof(hash_table_item));
    return table;
}

hash_table *hash_table_new()
{
    hash_table *table = hash_table_new_specify_size(INITIAL_SIZE);
    return table;
}

static void hash_table_delete_item(hash_table_item *item)
{
    free(item->key);
    free(item->value);
    free(item);
}

void hash_table_delete_table(hash_table *table)
{
    for (int i = 0; i < table->size; i++)
    {
        hash_table_item *item = table->items[i];
        if (item != NULL && item != &HT_DELETED_ITEM)
        {
            hash_table_delete_item(item);
        }
    }
    free(table->items);
    free(table);
}

// TODO actually implement this
static int hash(const char *s)
{
    int count;

    for (count = 0; s[count] != '\0'; ++count);

    return count;
}

static int hash_table_get_hash(const char *s)
{
    return hash(s);
}


static void hash_table_resize(hash_table *table, int size) {
    // TODO remove debug printing
    printf("Resize Called");
    if (size < INITIAL_SIZE) {
        return;
    }
    hash_table *new_table = hash_table_new_specify_size(size);

    for (int i = 0; i < table->size; i++) {
        hash_table_item *item = table->items[i];
        if ((item != NULL) && (item != &HT_DELETED_ITEM)) {
            hash_table_insert(new_table, item->key, item->value);
        }
    }

    const int tmp_size = table->size;
    table->size = new_table->size;
    new_table->size = tmp_size;

    hash_table_item **tmp_items = table->items;
    table->items = new_table->items;
    new_table->items = tmp_items;

    hash_table_delete_table(new_table);
}


// TODO update once hash chain implemented
void hash_table_insert(hash_table *table, const char *key, const char *value) {
    hash_table_item *item = hash_table_new_item(key, value);

    const int load = table->count * 100 / table->size;

    // TODO remove debug printing
    printf("Load: %d\n", load);

    if (load > RESIZE_LOAD_LIMIT) {
        hash_table_resize(table, table->size * 2);
    }

    int index = hash_table_get_hash(key);
    hash_table_item *current_item = table->items[index];
    // Only increment if we're not overwriting existing entry
    if (current_item == NULL || current_item == &HT_DELETED_ITEM) {
        table->count++;
    }
    table->items[index] = item;
}

// TODO update once hash chain implemented
char *hash_table_get(hash_table *table, const char *key){
    int index = hash_table_get_hash(key);
    return table->items[index]->value;
}

// TODO implement downsize
// TODO update once hash chain implemented
void hash_table_delete(hash_table *table, const char *key) {
    int index = hash_table_get_hash(key);
    hash_table_item *item = table->items[index];
    hash_table_delete_item(item);
    table->items[index] = &HT_DELETED_ITEM;
    table->count--;
}


// Need to free when done
char** hash_table_keys(hash_table table) {
    char **keys = malloc(table.count * sizeof(char*));
    int count = 0;
    for (int i = 0; i < table.size; i++){
        hash_table_item *item = table.items[i];
        if ((item != NULL) && (item != &HT_DELETED_ITEM)) {
            keys[count] = item->key;
            count++;
            continue;
        }
    }
    return keys;
}