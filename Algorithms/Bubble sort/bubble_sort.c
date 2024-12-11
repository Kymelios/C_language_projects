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

void printSortedArray(int arr[], int arrSize)
{
    printf("Sorted array: ");
    for (int i = 0; i < arrSize; i++)
    {
        printf("-%d-", arr[i]);
    }
}

int main()
{
    int arr[] = {2, 1, 7, 6, 0}; // 4 * 5 = 20 bytes
    int arrSize = sizeof(arr) / sizeof(int); // 20 / 4 = 5 

    bubbleSort(arr, arrSize);
    printSortedArray(arr, arrSize);

    return 0;
}