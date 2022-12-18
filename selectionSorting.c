#include <stdio.h>

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selectionSort(int *arr, int size)
{
    printf("Selection Sort running...\n");
    int indexOfMin, temp;
    for (int i = 0; i < size - 1; i++)
    {
        indexOfMin = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[indexOfMin])
            {
                indexOfMin = j;
            }
        }
        // Swap A[i] and A[indexOfMin]
        temp = arr[i];
        arr[i] = arr[indexOfMin];
        arr[indexOfMin] = temp;
    }
}

int main()
{
    int arr[] = {12, 65, 89, 4, 51, 24, 65};
    // int arr[] = {3, 5, 2, 13, 12};
    int size = sizeof(arr) / sizeof(int);
    printArray(arr, size);
    selectionSort(arr, size); // Time Complexity O(n^2)
    printArray(arr, size);

    return 0;
}