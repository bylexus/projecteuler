#include <stdbool.h>

#define HASHMAP_SIZE 1000000

typedef struct ul_hashmap_node
{
    unsigned long key;
    unsigned long value;
    struct ul_hashmap_node *next;
} ul_hashmap_node;

typedef struct ul_hashmap
{
    ul_hashmap_node **buckets;
} ul_hashmap;

ul_hashmap *ul_hashmap_create();
void ul_hashmap_free(ul_hashmap *map);
ul_hashmap_node *ul_hashmap_set(ul_hashmap *map, unsigned long key, unsigned long value);
ul_hashmap_node *ul_hashmap_get(ul_hashmap *map, unsigned long key);
void ul_hashmap_print(ul_hashmap *map);

typedef struct list_node
{
    void *data;
    struct list_node *next;
    struct list_node *prev;
} list_node;

list_node *list_node_create(void *data, size_t datasize);
list_node *list_node_prepend(list_node *list, void *data, size_t datasize);
void list_node_free(list_node *list);
void list_node_free_all(list_node *list);

bool isPrime(unsigned long nr);
