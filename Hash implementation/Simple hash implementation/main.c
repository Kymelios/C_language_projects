#include <stdio.h>
#include <limits.h>
#include <time.h>

#define HASH_TABLE_SIZE 10

unsigned int hashFunction(const char* str)
{
    unsigned int hash = 0;
    while (*str)
    {
        hash = (hash << 2) + *str;
        //printf("->%u\t\t %c\n", hash, *str); Just to check how it works
        str++;
    }

    return hash % 10; //Limits hash index from 0 to 9 based on hash table size
}

int main()
{
    clock_t start, end; //Variables for calculating clock ticks of program execution
    double cpu_time_used;
    unsigned int hashTable[HASH_TABLE_SIZE] = {0};

    const char* str[] = {"Hello", "World", "!"};

    start = clock();

    for (int i = 0; i < 3; i++)
    {
        unsigned int hashValue = hashFunction(str[i]);
        hashTable[hashValue]++;
        printf("%s\t| index: %u\n", str[i], hashValue);
    }

    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC; // Converting to seconds

    printf("Execution Time: %.6f seconds\n", cpu_time_used);

    return 0;
}