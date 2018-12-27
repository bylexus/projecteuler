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
