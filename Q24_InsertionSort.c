#include <stdio.h>

void insertionSort(int arr[], int n){
   
    if(n==0 || n==1) return;
    int cur = 0, j = 0;
    
   
    for(int i = 1; i < n; i++){
        
        cur = arr[i];
        j = i-1;
        
        while(j >= 0 && arr[j] > cur){
            arr[j+1] = arr[j];
            j--;
        }
        
       
        arr[j+1] = cur;
        
    }
    
}


void printArr(int arr[], int n){  
    int i;  
    for (i = 0; i < n; i++)  
        printf("%d ", arr[i]);  
}  
  
int main(){
   
    int arr[] = { 78, 90, 12, 42, 30, 65, 92 };  
   
    int n = sizeof(arr) / sizeof(arr[0]);  
    
    
    printf("Array elements initially - \n");  
    printArr(arr, n); 
    
   
    insertionSort(arr, n);
    
  
    printf("\nArray elements after applying insertion sort - \n");    
    printArr(arr, n); 

    return 0;
}
