#include <stdio.h>

int findMaxValue(int arr[], int arrSize)
{
    int maxValue = arr[0]; 

    for (int i = 1; i < arrSize; i++)
    {
        if (arr[i] > maxValue) //By changing to < you will get a minimum value
        {
            maxValue = arr[i];
        }
    }
    
    return maxValue;
}

int main()
{
    int arr[6] = {3, 1, 6, 9, 1, 124}; //int is 4 bytes and you have 6 elements, so 4 * 6 = 24 bytes
    int arrSize = sizeof(arr) / sizeof(int); // Number of elements in the array 24 / 4 = 6 
    printf("Max value: %d\n", findMaxValue(arr, arrSize));

    return 0;
}