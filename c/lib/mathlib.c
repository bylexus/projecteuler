#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "./mathlib.h"

bool isPrime(unsigned long nr)
{
    float border = sqrtf((double)nr);
    if (nr == 2)
        return true;
    if (nr % 2 == 0)
    {
        return false;
    }
    for (unsigned long i = 3; i <= border; i++)
    {
        if (nr % i == 0)
        {
            return false;
        }
    }
    return true;
}

ul_hashmap *ul_hashmap_create()
{
    ul_hashmap *map = malloc(sizeof(ul_hashmap));
    map->buckets = malloc(sizeof(ul_hashmap_node *) * HASHMAP_SIZE);
    for (int i = 0; i < HASHMAP_SIZE; i++)
    {
        map->buckets[i] = NULL;
    }
    return map;
}

ul_hashmap_node *ul_hashmap_node_create(unsigned int key, unsigned int value)
{
    ul_hashmap_node *node = malloc(sizeof(ul_hashmap_node));
    node->key = key;
    node->value = value;
    node->next = NULL;
    return node;
}

void ul_hashmap_node_free(ul_hashmap_node *node)
{
    if (node != NULL)
    {
        if (node->next)
        {
            ul_hashmap_node_free(node->next);
        }
        free(node);
    }
}

void ul_hashmap_free(ul_hashmap *map)
{
    for (int i = 0; i < HASHMAP_SIZE; i++)
    {
        ul_hashmap_node_free(map->buckets[i]);
    }
    free(map);
}

ul_hashmap_node *ul_hashmap_set(ul_hashmap *map, unsigned long key, unsigned long value)
{
    int composed_key = key % HASHMAP_SIZE;
    ul_hashmap_node *head = map->buckets[composed_key];
    ul_hashmap_node *newNode = ul_hashmap_node_create(key, value);
    if (head)
    {
        newNode->next = map->buckets[composed_key];
    }
    else
    {
        newNode->next = NULL;
    }
    map->buckets[composed_key] = newNode;
    return newNode;
}

ul_hashmap_node *ul_hashmap_get(ul_hashmap *map, unsigned long key)
{
    int composed_key = key % HASHMAP_SIZE;
    ul_hashmap_node *head = map->buckets[composed_key];
    while (head != NULL)
    {
        if (head->key == key)
        {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

void ul_hashmap_print(ul_hashmap *map)
{
    ul_hashmap_node *node;
    for (int i = 0; i < HASHMAP_SIZE; i++)
    {
        node = map->buckets[i];
        while (node != NULL)
        {
            printf("Bucket: %d, Key: %lu, Value: %lu\n", i, node->key, node->value);
            node = node->next;
        }
    }
}

list_node *list_node_create(void *data, size_t datasize)
{
    list_node *node = malloc(sizeof(list_node));
    node->data = malloc(datasize);
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

list_node *list_node_prepend(list_node *list, void *data, size_t datasize)
{
    list_node *node = list_node_create(data, datasize);
    if (list != NULL)
    {
        list_node *prev = list->prev;
        node->next = list;
        node->prev = prev;
        list->prev = node;
        if (prev != NULL)
        {
            prev->next = node;
        }
    }
    return node;
}

void list_node_free(list_node *list)
{
}

void list_node_free_all(list_node *list)
{
}

/**
 * sum of (single) divisors of n.
 * For example:
 * proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110;
 * therefore divsum(220) = 284
 */
int divsum(int n)
{
    int sum = 1;
    int divOp;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            sum += i;
            divOp = n / i;
            if (divOp > i)
            {
                sum += divOp;
            }
        }
    }
    return sum;
}

/**
 * Binary search: searches for a specific number within
 * the given array, return its index.
 * Returns -1 if not found.
 */
int binsearch(int search, int *arr, int start, int end)
{
    int mid = (start + end) / 2;
    if (arr[mid] == search)
    {
        return mid;
    }
    if (search < arr[mid] && start < mid)
    {
        return binsearch(search, arr, start, mid - 1);
    }
    if (search > arr[mid] && mid < end)
    {
        return binsearch(search, arr, mid + 1, end);
    }
    return -1;
}

/**
 * Sorts the given char array by using selection sort in-place.
 */
void selectionSort(char **names, int len)
{
    char *tmp;
    for (int i = 0; i < len; i++)
    {
        int maxindex = i;
        for (int uidx = i; uidx < len; uidx++)
        {
            if (strcmp(names[maxindex], names[uidx]) > 0)
            {
                maxindex = uidx;
            }
        }
        tmp = names[i];
        names[i] = names[maxindex];
        names[maxindex] = tmp;
    }
}

int quickSort_divide(char **names, int left, int right)
{
    int i = left;
    int j = right - 1;
    char *tmp;
    int pivot = right;

    do
    {

        // Suche von links ein Element, welches größer als das Pivotelement ist
        while (strcmp(names[i], names[pivot]) < 0 && i < right - 1)
        {
            i++;
        }

        // Suche von rechts ein Element, welches gleich oder kleiner als das Pivotelement ist
        while (strcmp(names[j], names[pivot]) >= 0 && j > left)
        {
            j--;
        }

        if (i < j)
        {
            tmp = names[i];
            names[i] = names[j];
            names[j] = tmp;
        }

    } while (i < j);

    // Tausche Pivotelement (daten[rechts]) mit neuer endgültiger Position (daten[i])
    if (strcmp(names[i], names[pivot]) >= 0)
    {
        tmp = names[i];
        names[i] = names[pivot];
        names[pivot] = tmp;
    }
    // gib die neue Position des Pivotelements zurück, beende Durchlauf
    return i;
}

/**
 * Sorts the given char array by using quicksort sort in-place.
 */
void quickSort(char **names, int left, int right)
{
    int pivot;
    if (left < right)
    {
        pivot = quickSort_divide(names, left, right);
        quickSort(names, left, pivot);
        quickSort(names, pivot + 1, right);
    }
}

unsigned long factorial(int n)
{
    unsigned long res = 1;
    while (n > 0)
    {
        res = res * n--;
    }
    return res;
}

// ----------------- BIGNUM  -----------------------

bignum_int *bignum_int_create(int max_digits, int init)
{
    bignum_int *b = malloc(sizeof(bignum_int));
    b->length = 1;
    b->max_digits = max_digits;
    b->digits = malloc(max_digits * sizeof(char));
    b->digits[0] = 0;
    bignum_int_add_int(b, init);
    return b;
}

char *bignum_int_str(bignum_int *bignum)
{
    char *str = malloc((bignum->length + 1) * sizeof(char));
    for (int i = bignum->length - 1; i >= 0; i--)
    {
        str[bignum->length - i - 1] = bignum->digits[i] + 48;
    }
    str[bignum->length] = '\0';
    return str;
}

bool bignum_int_add_int(bignum_int *bignum, int nr)
{
    for (int i = 0; i < bignum->length; i++)
    {
        nr = bignum->digits[i] + nr;
        bignum->digits[i] = nr % 10;
        nr = nr / 10;
    }
    while (nr > 0)
    {
        if (bignum->max_digits > bignum->length + 1)
        {
            bignum->length++;
            bignum->digits[bignum->length - 1] = nr % 10;
            nr = nr / 10;
        }
        else
        {
            return false;
        }
    }
    return true;
}

bignum_int *bignum_int_sum(bignum_int *b1, bignum_int *b2, int max_digits)
{
    int tmp = 0;
    int len = b1->length > b2->length ? b1->length : b2->length;
    bignum_int *sum = bignum_int_create(max_digits, 0);
    for (int i = 0; i < len; i++)
    {
        int n1 = i < b1->length ? b1->digits[i] : 0;
        int n2 = i < b2->length ? b2->digits[i] : 0;
        tmp = n1 + n2 + tmp;
        sum->digits[i] = tmp % 10;
        tmp = tmp / 10;
    }
    sum->length = len;
    while (tmp > 0 && sum->length <= sum->max_digits)
    {

        sum->length++;
        sum->digits[sum->length - 1] = tmp % 10;
        tmp = tmp / 10;
    }
    return sum;
}

void bignum_int_free(bignum_int *bn)
{
    if (bn != NULL)
    {
        free(bn);
    }
}
