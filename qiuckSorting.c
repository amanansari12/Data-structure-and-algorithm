#include <stdio.h>

void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (arr[i] <= pivot)
        {
            i++;
        }

        while (arr[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } while (i < j);

    // Swap A[low] and A[j]
    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
}

void quickSort(int arr[], int low, int high)
{   
    int partitionIndex; // Index of pivot after partition

    if (low < high)
    {
        partitionIndex = partition(arr, low, high); 
        quickSort(arr, low, partitionIndex - 1);  // sort left subarray 
        quickSort(arr, partitionIndex + 1, high); // sort right subarray
    }
}

int main()
{
    //int A[] = {3, 5, 2, 13, 12, 3, 2, 13, 45};
    int arr[] = {9, 4, 4, 8, 7, 5, 6};
    int size = sizeof(arr)/sizeof(int);
    printArray(arr, size);
    printf("Running Quick sort....\n"); 
    quickSort(arr, 0, size - 1); // Time Complexity: Best Case--> O(nlogn) || Worst Case--> O(n^2)
    printArray(arr, size);
    return 0;
}
