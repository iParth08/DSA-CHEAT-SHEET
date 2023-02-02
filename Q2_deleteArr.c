// Delete element at particular position in array


#include<stdio.h>

int deleteAtPos(int arr[], int size){
    int pos;
    printf("Enter position to delete element: ");
    scanf("%d", &pos);

    size -= 1;
    for(int i=pos-1; i<size; i++)
        arr[i] = arr[i+1];
    
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

    size = deleteAtPos(arr, size);

    display(arr, size);

    return 0;
}