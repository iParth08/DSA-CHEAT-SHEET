#include<stdio.h>
void towerOfHanoi(int n,char beg,char aux,char end){
    if (n==1){
        printf("\nMove dish 1 from %c to %c", beg, end);
        return;
    }
    else {
    towerOfHanoi(n-1, beg, end, aux);
    printf("\nMove dish %d from %c to %c",n, beg, end);
    towerOfHanoi(n-1, aux, beg, end);
    }
}
int main()
{
int n;
printf("Enter Number: ");
scanf("%d",&n);
printf("Print Tower of Hanoi steps:\n");
towerOfHanoi(n, 'A', 'B', 'C');
return 0;
}