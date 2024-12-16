#include <stdio.h>

void printArr2D()
{
    int arr6[][2] = {{1, 2}, {3, 4}};
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d", arr6[i][j]);
        }
     printf("\n");   
    }
}

void printArr3D()
{
    int arr9[][2][2] = {{1, 2, 3 ,4}, {5, 6, 7, 8}};
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int d = 0; d < 2; d++)
            {
                printf("%d", arr9[i][j][d]);
            }
         printf("\n");   
        }
     printf("\n");   
    }
}

int main()
{
    int arr1[3];
    int arr2[3] = {1, 2 ,3};
    int arr3[] = {1, 2 ,3};

    printf("2D Array:\n");
    printArr2D();
    printf("\n");

    int arr4[2][2];
    int arr5[2][2] = {{1, 2}, {3, 4}};
    //int arr6[][] = {{1, 2}, {3, 4}}; // incomplete type "int [][]" is not allowed

    printf("3D Array:\n");
    printArr3D();

    int arr7[2][2][2];
    int arr8[2][2][2] = {{1, 2, 3 ,4}, {5, 6, 7, 8}};
    //int arr9[][][] = {{1, 2, 3 ,4}, {5, 6, 7, 8}}; // incomplete type "int [][][]" is not allowed

    printf("Address of the arr1: %p\n", arr1); //arr1 points to arr1[0] (first element of the array)
    printf("Address of the first element in arr1 %p\n\n", &arr1[0]); //Here we get an address of the first element of the array

    return 0;
}