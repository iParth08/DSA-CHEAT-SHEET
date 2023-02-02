// Insert element at particular position in array


#include<stdio.h>

int insertAtPos(int arr[], int size){
    int pos, elm;
    printf("Enter position : ");
    scanf("%d", &pos);

    printf("Enter element to add : ");
    scanf("%d", &elm);

    size += 1;
    for(int i=size-1; i>pos-1; i--)
        arr[i] = arr[i-1];
    
    arr[pos-1] = elm;

    return size;
}

void display(int arr[], int size){
    printf("Array Contents :: ");
    for(int i=0; i<size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    int arr[20], size;

    printf("Enter size of array(<20) : ");
    scanf("%d", &size);

    printf("Enter elements : ");
    for(int i=0; i<size; i++)
        scanf("%d", &arr[i]);

    display(arr, size);

    size = insertAtPos(arr, size);

    display(arr, size);

    return 0;
}