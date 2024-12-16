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
So what actually happens here is when we pass an array into a function, it is treated as a pointer to the first element of the array, not as an array itself. As a result,   `sizeof(arr)` will return the size of the pointer, not the size of the array. And that is why I couldn't do it inside a function.













