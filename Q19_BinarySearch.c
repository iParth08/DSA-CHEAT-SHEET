#include<stdio.h>


int binary_search(int *a, int n, int k)
{
    
    int start = 0, end = n-1;
    int mid;

    
    while(start <= end)
    {
      
        mid = start + ((end - start) / 2);
        
       
        if(k == a[mid])
        {
            return mid;
        }
  
        else if(k < a[mid])
        {
            end = mid - 1;
        }
        
        
        else if(k > a[mid])
        {
            start = mid + 1;
        }
    }
    
    return -1;
}

int main()
{
    
    int arr[7] = {2, 5, 7, 10, 12, 15, 18};

  
    int data;
    printf("Enter element to find (iterative binary search): ");
    scanf("%d", &data);

     
    int result = binary_search(arr, 7, data);

    
    if(result != -1)
    {
        printf("\nElement Found at Position: %d, Index: %d\n", result + 1, result);
    }
    else
    {
        printf("\nElement not found");
    }

    return 0;
}

