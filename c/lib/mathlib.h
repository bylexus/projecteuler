#include <stdbool.h>
#include <string.h>

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

/**
 * Sorts the given char array by using selection sort in-place.
 */
void selectionSort(char **names, int len);

/**
 * Sorts the given char array by using quicksort sort in-place.
 */
void quickSort(char **names, int left, int right);

unsigned long factorial(int n);


// ----------------- BIGNUM  -----------------------
/**
 * Defines a big integer number. This struct should always
 * be used with the bignum_int*-functions
 */
typedef struct {
    int max_digits;
    char *digits;
    int length;
} bignum_int;

/**
 * Creates a bignum_int object and returns a pointer to it.
 */
bignum_int *bignum_int_create(int max_digits, int init);

/**
 * frees the memory allocated by the given bignum_int object
 */
void bignum_int_free(bignum_int* bn);

/**
 * Returns a pointer to a string, representing the big number
 */
char *bignum_int_str(bignum_int *bignum);


/**
 * Adds a normal integer to the bignum,
 * returning 1 on success, 0 on failure
 */
bool bignum_int_add_int(bignum_int *bignum, int nr);

/**
 * Sums up 2 bignum_int numbers, returning the pointer to the result number
 */
bignum_int *bignum_int_sum(bignum_int *b1, bignum_int *b2, int max_digits);
