typedef struct
{
    char *key;
    char *value;
} hash_table_item;

typedef struct
{
    int count;
    int size;
    hash_table_item **items;
} hash_table;

hash_table *hash_table_new();

void hash_table_delete_table(hash_table *table);

void hash_table_insert(hash_table *table, const char *key, const char *value);

char *hash_table_get(hash_table *table, const char *key);

void hash_table_delete(hash_table *table, const char *key);

// Need to free when done
char** hash_table_keys(hash_table table);