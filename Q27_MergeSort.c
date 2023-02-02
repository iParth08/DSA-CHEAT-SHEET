#include <stdio.h>
 
void merge(int sorted[], int start, int mid, int end) {
 
  
  int m1 = mid - start + 1;
  int m2 = end - mid;
 
  int arr1[m1], arr2[m2];
 
  for (int i = 0; i < m1; i++)
    arr1[i] = sorted[start + i];
  for (int j = 0; j < m2; j++)
    arr2[j] = sorted[mid + 1 + j];
 
  
  int i, j, k;
  i = 0;
  j = 0;
  k = start;
 
  
  while (i < m1 && j < m2) {
    if (arr1[i] <= arr2[j]) {
      sorted[k] = arr1[i];
      i++;
    } else {
      sorted[k] = arr2[j];
      j++;
    }
    k++;
  }

 
  while (i < m1) {
    sorted[k] = arr1[i];
    i++;
    k++;
  }
 
  while (j < m2) {
    sorted[k] = arr2[j];
    j++;
    k++;
  }
}
 

void mergeSort(int arr[], int start, int end) {
  if (start < end) {
 

    int mid = start + (end - start) / 2;
 
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
 
    
    merge(arr, start, mid, end);
  }
}
 
int main() {
  int arr[] = {6, 5, 4, 8, 1, 9};
  int size = sizeof(arr) / sizeof(arr[0]);
 
  mergeSort(arr, 0, size - 1);
  printf("After sorted Array==>> \n");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
  printf("\n");
}
