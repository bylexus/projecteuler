#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "./lib/mathlib.h"

/**
 * @see https://projecteuler.net:
 *
 * Names scores
 * Problem 22
 *
 * Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names,
 * begin by sorting it into alphabetical order. Then working out the alphabetical value for each name,
 * multiply this value by its alphabetical position in the list to obtain a name score.
 *
 * For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list.
 * So, COLIN would obtain a score of 938 × 53 = 49714.
 *
 * What is the total of all the name scores in the file?
 */

char *cleanStr(char *str)
{
    int i;
    char *newStr = malloc(sizeof(char) * (strlen(str) - 2));
    for (i = 0; i < strlen(str) - 2; i++)
    {
        newStr[i] = str[i + 1];
    }
    newStr[i] = '\0';
    return newStr;
}

int readNames(char **names)
{

    const char filename[] = "problem_0022-input.txt";
    int nrOfNames = 0;

    FILE *fp = fopen(filename, "r");
    char *token;
    // int i;
    if (fp != NULL)
    {
        char line[50000];
        while (fgets(line, sizeof line, fp) != NULL)
        {
            token = strtok(line, ",");
            while (token != NULL)
            {
                char *newStr = cleanStr(token);
                names[nrOfNames++] = newStr;
                token = strtok(NULL, ",");
            }
        }
        fclose(fp);
    }
    else
    {
        perror(filename);
    }
    return nrOfNames;
}

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

int main(void)
{
    char *names[6000];
    int len = readNames(names);
    int sum = 0;
    int wordsum = 0;
    printf("Read %d names\n", len);
    selectionSort(names, len);
    for (int i = 0; i < len; i++)
    {
        wordsum = 0;
        for (int l = 0; l < strlen(names[i]); l++)
        {
            wordsum += names[i][l] - 64;
        }
        sum += (wordsum * (i+1));
    }
    printf("Word sum of all names: %d\n",sum);
}
