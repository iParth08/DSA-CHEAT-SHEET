#include<stdio.h>


int linearSearch(int arr[], int size, int key) {
  int index;
  
  for (index = 0; index < size; index++)
    if (arr[index] == key) 
      return index;
  return -1;
}

int main() {
  
  int arr[20], size, key, i, index;
  printf("Number of elements in the list: ");
  scanf("%d", &size);

  printf("Enter elements of the list: ");
  
  for (i = 0; i < size; i++)
    scanf("%d", &arr[i]);

  printf("Enter the element to search ie. key element: ");
  scanf("%d", &key);

  index = linearSearch(arr, size, key); 

  if (index == -1) 
    printf("Key element not found");
  else
    printf("Key element found at index %d", index); 

  return 0;
}
