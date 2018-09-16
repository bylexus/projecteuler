#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "./lib/mathlib.h"

/**
 * @see https://projecteuler.net:
 *
 * Largest prime factor
 * Problem 3
 *
 * The prime factors of 13195 are 5, 7, 13 and 29.
 *
 * What is the largest prime factor of the number 600851475143 ?
 */

typedef struct node
{
    unsigned long data;
    struct node * next;
} node_t;

node_t  * head = NULL;


void primeFactorize(unsigned long nr)
{
    unsigned long act = 2;
    node_t * newNode = NULL;
    while (act <= nr)
    {
        if (nr % act == 0)
        {
            newNode = malloc(sizeof(node_t));
            newNode->data = act;
            newNode->next = head;
            head = newNode;
            unsigned long fact = nr / act;
            if (fact > 2)
            {
                primeFactorize(fact);
            }
            else if (fact > 1)
            {
                newNode = malloc(sizeof(node_t));
                newNode->data = fact;
                newNode->next = head;
                head = newNode;
            }
            return;
        }
        act++;
        while (!isPrime(act))
            act++;
    }
}

int main(void)
{

    // unsigned long testNumber = 128;
    unsigned long testNumber = 600851475143L;
    unsigned long biggest = 0;
    primeFactorize(testNumber);

    //Output prime factors:
    printf("Prime factors:\n");
    node_t * act = head;
    while (act != NULL) {
        biggest = act->data > biggest ? act->data : biggest;
        printf("  %lu\n", act->data);
        act = act->next;
    }
    printf("Solution: %lu\n", biggest);
}
