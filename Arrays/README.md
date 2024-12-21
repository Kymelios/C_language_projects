# Arrays implementation and more (In progress)
In this section I want to show the principles of array operation and problems I faced with during coding.

## Basic array implementation
- **A single-dimensional array** is a simple linear data structure where elements are stored in a single row (contiguous blocks of memory).
<br> You can declare and initialize them somehow like this:
```
    int arr1[3]; // Declaration of an array of integers

    int arr2[3] = {1, 2 ,3}; // Declaration of an array of integers and their direct initialization (list-initialization)

    int arr3[] = {1, 2 ,3}; // Declaration of an array of integers without specified amount of elements with list-initialization
```
- With **2D and 3D arrays** almost indentical situation. In 2D array adds another dimenstion (column) so it starts looking like matrix with rows and columns. 
  <br>
- In 3D array case, we have the same 2D array or matrix but with third dimension they just overlap each other, so it creates the 3D look.
<br> You can declare and initialize them somehow like this:
```
  //2D Array
    int arr4[2][2];

    int arr5[2][2] = {{1, 2}, {3, 4}};

    int arr6[][] = {{1, 2}, {3, 4}}; // incomplete type "int [][]" is not allowed

  //3D Array
    int arr7[2][2][2];

    int arr8[2][2][2] = {{1, 2, 3 ,4}, {5, 6, 7, 8}};

    int arr9[][][] = {{1, 2, 3 ,4}, {5, 6, 7, 8}}; // incomplete type "int [][][]" is not allowed
```

The reason why we get error in `int arr6[][] = {{1, 2}, {3, 4}};` and `arr9[][][] = {{1, 2, 3 ,4}, {5, 6, 7, 8}};` is because compiler needs to know the sizes of **columns (second dimension)** and **layers (third dimension)**.
<br><br>
So to fix this, you need to explicitly define the second and third dimensions: `int arr6[][2] = {{1, 2}, {3, 4}};` and `arr9[][2][2] = {{1, 2, 3 ,4}, {5, 6, 7, 8}};` and after this our problem will be solved. Also if you noticed, we omitted initialization of the first dimension, this is because the compiler can count them for you based on the data you provide like second and third demension.


---
---
## The problems I faced with
### Problem 1
- The first problem I faced with, was when I tried to implement bubble sort. I passed an array into a function as an argument and tried to find its size inside that function like this:
```
#include <stdio.h>

void bubbleSort(int arr[])
{
    int arrSize = sizeof(arr) / sizeof(int);

    for (int i = 0; i < arrSize - 1; i++)
    {
        for (int j = 0; j < arrSize - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int arr[] = {3, 2, 1};
    bubbleSort(arr);

    return 0;
}
```
If you try to compile this program, you will get a warning like this:
```
warning: 'sizeof' on array function parameter 'arr' will return size of 'int *' [-Wsizeof-array-argument]
```
So what actually happens here is when we pass an array into a function, it is treated as a pointer to the first element of the array, not as an array itself. As a result,   `sizeof(arr)` will return the size of the pointer, not the size of the array. And that is why you can't do it inside a function.

And the easiest way to fix it is to calculate arrSize directly in the main function and pass it as an argument to the function. Like in this example:
```
#include <stdio.h>

void bubbleSort(int arr[], int arrSize)
{
    for (int i = 0; i < arrSize - 1; i++)
    {
        for (int j = 0; j < arrSize - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int arr[] = {2, 1, 7, 6, 0}; // 4 * 5 = 20 bytes
    int arrSize = sizeof(arr) / sizeof(int); // Calculating arrSize 20 / 4 = 5 

    bubbleSort(arr, arrSize);

    return 0;
}
```



---

### Problem 2
**"a variable length array cannot have static storage duration C/C++"**
```
int* arrInit(int arrSize)
{
    static int arr[arrSize]; //This makes an error
    for (int i = 0; i < arrSize; i++)
    {
        arr[i] = i;
    }

    return arr;
}
```
- In this case, I tried to declare and initialize a static array in function during runtime. But the problem here is that **arrSize** is only known at runtime, making <ins>arr</ins> a Variable Length Array (VLA). And it doesn't allow us to use a keyword **static** together with VLAs because they cannot have static storage duration and static arrays require their size to be determined at **compile time** in order to allocate memory in static storage.

To fix that problem there are several ways to do it, but I will point out two solutions that I found out to be a good examples:
<br>
#### 1) **The first one is to use a constant!**
You can use a **#define preprocessor directive** constant, that is not really flexible when you want to create several arrays with different sizes, but good if array size is always known and constant at compile time.
```
#define ARR_SIZE 100

int* arrInit()
{
    static int arr[ARR_SIZE];
    for (int i = 0; i < ARR_SIZE; i++)
    {
        arr[i] = i;
    }

    return arr;
}
```
#### 2) **The second one is to allocate memory dynamically!**
If you want to have a dynamically allocated array with static storage duration, this approach is also valid. The memory will be allocated on the heap, and you will have to free the memory when you're done using it to avoid memory leaks, etc.
```
int* arrInit(int arrSize)
{
    static int* arr;
    arr = malloc(arrSize * sizeof(int));

    for (int i = 0; i < arrSize; i++)
    {
        arr[i] = i;
    }

    return arr;
}
```












