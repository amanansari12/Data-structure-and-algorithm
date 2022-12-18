// Bubble sort is not adaptive, we can make it adaptive.

// We will make an integer variable isSorted which would hold 1 if our array is sorted and 0 otherwise. 
// Make isSorted equal to 1 prior to starting any comparison in each pass. 
// If any of our comparisons demands swapping of elements, 
// we switch isSorted to 0. 

// At the end of each pass, check if the isSorted changed to 0. 
// If it did, our array was not yet sorted; otherwise, end the comparison there itself, 
// since our array was already sorted.




#include<stdio.h>

void printArray(int *arr, int size){
    for (int i = 0; i < size; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void bubbleSort(int *arr, int size){
    int temp;
    int isSorted =0;
    for (int i = 0; i < size-1; i++) // For number of pass
    {
        // printf("Number of Passes %d\n", i+1);
        isSorted=1;
        // printArray(arr,size);
        for (int j = 0; j < size-1-i; j++) // For comparison in each pass
        {
            if (arr[j]>arr[j+1])
            {
            temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
            isSorted =0;
            }
            
        }
        if (isSorted == 1)
        {
           return;
        }
        
    }
    
}

int main (){
    int arr[]={1, 2, 5, 6, 12, 54, 625, 7, 23, 9, 987};
    // int arr[]={1,2,3,4,5,6,7,8,9};
    int size=sizeof(arr)/sizeof(int);
    printArray(arr,size);
    bubbleSort(arr,size);
    printArray(arr,size);
    return 0;
}