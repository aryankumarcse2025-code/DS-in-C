#include<stdio.h>
void createArray(int* arr, int n){

    printf("Enter the values in array: \n");
    for(int i = 0; i<n; i++){
        printf("Enter value of index %d: ", i);
        scanf("%d", &arr[i]);
    }
    printf("\n");
}
void printArray(int arr[], int n){

    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partion(int* arr, int low, int high){
    int pivot = arr[low];

    int i = low;
    int j = high;

    while(i<j){

        while(arr[i]<=pivot && i<=high) i++;
        while(arr[j] > pivot && j>=low) j--;

        if(i<j) swap(&arr[i], &arr[j]);
    }
    swap(&arr[low], &arr[j]);
    return j;
}
void quickSort(int* arr, int low, int high){
    if(low>=high) return;

    int pIdx = partion(arr, low, high);
    quickSort(arr, low, pIdx-1);
    quickSort(arr, pIdx+1, high);
}
int main(){
    int arr[100];
    int n;
    printf("Enter the size of Array: ");
    scanf("%d", &n);

    createArray(arr, n);

    printf("Original Array: ");
    printArray(arr, n);

    quickSort(arr, 0, n-1);

    printf("Sorted Array: ");
    printArray(arr, n);

    return 0;
}