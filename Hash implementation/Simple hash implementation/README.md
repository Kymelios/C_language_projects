# Simple Hash Implementation
Here, I have implemented a simple hash table. I can't say it is not a data structure, 
but it is quite limited compared to a struct-based implementation. However, 
it is a good way to understand the principles of how it works.

## Features
1. Ability to check how long it takes to hash our strings using `time.h` library.

## How It Works

1. We define a small array of strings "Hello", "World", "!" for hashing.
2. Each string is hashed using a `hashFunction()`.
3. Hash values we get after function `return hash % 10;` become indexes in hash table.
4. The program prints the mapping and calculates execution time.


## Output of the program:
```
Hello   | index: 7
World   | index: 2
!       | index: 3
Execution Time: 0.001000 seconds
```
