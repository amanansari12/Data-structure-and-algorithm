#include<stdio.h>
#include<stdlib.h>

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void merge(int arr[], int low, int mid, int high){
    int i,j,k;
    i=low;
    j=mid+1;
    k=low;
    int c= (high-low)+1;

    int *arr1=(int *)malloc(c*sizeof(int));
    // int *arr1=malloc(c);
    // int arr1[7];

    while (i<=mid && j<=high)
    {
        if (arr[i]<arr[j])
        {
            arr1[k]=arr[i];
            i++; k++;
        }
        else{
            arr1[k]=arr[j];
            j++; k++;
        }
        
    }
    while (i<=mid)
    {
        arr1[k]=arr[i];
            i++; k++;
    }
    while (j<=high)
    {
        arr1[k]=arr[j];
            j++; k++;
    }

    for (int i = low; i <= high; i++)
    {
       arr[i]=arr1[i];
    }
    
    // if (k==high)
    // {
    //     free(arr1);
    // }
    

}

void mergeSort(int arr[], int low, int high){
     int mid;
    if (low<high)
    {   mid=(low+high)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
    
}
int main (){
    int arr[] = {12, 65, 89, 4, 51, 24, 65};
    // int arr[] = {3, 5, 2, 13, 12}; 
    int size = sizeof(arr) / sizeof(int);
    printArray(arr, size);
    mergeSort(arr, 0, size-1);
    printArray(arr, size);
    return 0;
}