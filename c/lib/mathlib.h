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
    ul_hashmap_node** buckets;
} ul_hashmap;

bool isPrime(unsigned long nr);

ul_hashmap *ul_hashmap_create();
void ul_hashmap_free(ul_hashmap *map);
ul_hashmap_node *ul_hashmap_set(ul_hashmap *map, unsigned long key, unsigned long value);
ul_hashmap_node *ul_hashmap_get(ul_hashmap *map, unsigned long key);
void ul_hashmap_print(ul_hashmap *map);
