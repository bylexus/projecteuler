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

/**
 * sum of (single) divisors of n.
 * For example:
 * proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110;
 * therefore divsum(220) = 284
 */
int divsum(int n);

/**
 * Binary search: searches for a specific number within
 * the given array, return its index.
 * Returns -1 if not found.
 */
int binsearch(int search, int *arr, int start, int end);
