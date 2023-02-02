#include <stdio.h>

// fibonacci() funtion definition
int fibonacci(int num)
{
    // first base condition check
    if (num == 0)
    {
        return 0; 
    }
    // second base condition check
    else if (num == 1)
    {
        return 1;
    }
    
    else
    {
        return fibonacci(num - 1) + fibonacci(num - 2); 
    }
}

int main()
{
    int num; 
    printf("Enter the number of elements to be in the series : ");
    scanf("%d", &num); 
    

    for (int i = 0; i < num; i++)
    {
        printf("%d, ", fibonacci(i)); 
    }

    return 0;
}
