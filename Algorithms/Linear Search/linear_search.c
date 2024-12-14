#include <stdio.h>

int findIndex(int arr[], int arrSize, int searchTarget)
{
    for (int i = 0; i < arrSize; i++)
    {
        if (arr[i] == searchTarget)
        {
            return i;
        }
    }

    return -1;
}

int main() {
    int arr[] = {-1, 4, 5, 6, 8};
    int arrSize = sizeof(arr) / sizeof(int);
    
    int result = findIndex(arr, arrSize, -1);

    if (result != -1)
    {
        printf("Element was found at index: %d\n", result);
    }
    else
    {
        printf("Element was not found!\n");
    }    

    return 0;
}