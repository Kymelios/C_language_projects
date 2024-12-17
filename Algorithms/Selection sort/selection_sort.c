#include <stdio.h>

void swap(int *firstValue, int *minValue)
{
    int temp = *firstValue;
    *firstValue = *minValue;
    *minValue = temp;
}

void selectionSort(int arr[], int arrSize)
{
    for (int i = 0; i < arrSize - 1; i++)
    {
        int min_value = i;
        for (int j = i + 1; j < arrSize; j++)
        {
            if (arr[j] < arr[min_value])
            {
                min_value = j;
            }
        }
        swap(&arr[i], &arr[min_value]);
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

int main() {
    int arr[] = {4, 9, 1, 12, 7}; // 4 * 5 = 20 bytes
    int arrSize = sizeof(arr) / sizeof(int); // 20 / 4 = 5 

    selectionSort(arr, arrSize);
    printSortedArray(arr, arrSize);

    return 0;
}