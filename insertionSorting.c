#include<stdio.h>

void printArray(int arr[], int size){
    for (int i = 0; i < size; ++i)
    {
        printf("%d ", arr[i]);
    }
     printf("\n");
}


void insertionSort(int *arr,int size){
    int key,j;
    for (int i = 1; i <= size-1; i++)
    {
        key=arr[i];
        j=i-1;
        while (j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
        
    }
    
}

int main (){
    int arr[]={12,65,89,4,51,24,65};
    int size =sizeof(arr)/sizeof(int);
    printArray(arr,size);
    insertionSort(arr,size); // Time Complexity O(n^2)
    printArray(arr,size); 

    return 0;
}