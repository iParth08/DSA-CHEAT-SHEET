// Search an element from particular position in array


#include<stdio.h>

void searchFromPos(int arr[], int size){
    int pos, elm, index=-1;
    printf("Enter position to search from: ");
    scanf("%d", &pos);

    printf("Enter element to search: ");
    scanf("%d", &elm);

    for(int i=pos-1; i<size; i++){
       if(arr[i] == elm)
            index = i;
    }
    
    if(index== -1)
        printf("Element %d not found!", elm);
    else
        printf("Element %d found at index %d", elm, index);
}

void display(int arr[], int size){
    printf("Array Contents :: ");
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

    display(arr, size);

    searchFromPos(arr, size);

    return 0;
}