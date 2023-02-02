// Sorting an array bubble sort


#include<stdio.h>

void bubbleSort(int arr[], int size){

    for(int i=0; i<size-1; i++){
        for(int j=0; j<size; j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    
}

void display(int arr[], int size){
    
    for(int i=0; i<size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    int arr[20], size, index;

    printf("Enter size of array(<20) : ");
    scanf("%d", &size);

    printf("Enter elements : ");
    for(int i=0; i<size; i++)
        scanf("%d", &arr[i]);

    printf("Array Contents :: \n");
    display(arr, size);

    bubbleSort(arr, size);

    printf("Sorted array in Ascending order : \n");
    display(arr, size);

    return 0;
}