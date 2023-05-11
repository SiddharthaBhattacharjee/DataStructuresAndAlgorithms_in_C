#include <stdio.h>

void swap(int* a,int* b){
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high){
    int i = low-1;
    int p = arr[high];
    for(int j=low;j<high;j++){
        if(arr[j]<p){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return(i+1);
}

void quicksort(int arr[], int low, int high){
    if(low<high){
        int pi = partition(arr,low,high);
        quicksort(arr,low,pi-1);
        quicksort(arr,pi+1,high);
    }
}

void printArray( int arr[], int len){
    for(int i=0;i<len;i++){
        printf(" %d",arr[i]);
    }
}

int main(){
    int arr[] = {9,2,4,1,3,6,7,5,8,0};
    int len = sizeof(arr)/4;
    printf("Array before Sorting : ");
    printArray(arr,len);
    quicksort(arr,0,len-1);
    printf("\nArray after sorting : ");
    printArray(arr,len);
    return 0;
}