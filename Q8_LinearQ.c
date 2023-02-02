#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 5

int Queue[MAX_SIZE];

int rear = -1, front = -1;

void display();
int dQueue();
void enQueue();

int main(){

    printf("\nChoose the following Operation\n");
    printf("\n0. Exit \t 01. enQueue \t 02. dQueue \t 03. Display \n");
    while(1){

        int choice;
        printf("\nChoice-->> ");
        scanf("%d",&choice);

        switch(choice){
            case 0: exit(0);
            case 1: enQueue();break;
            case 2: dQueue();break;
            case 3: display();break;
            default: printf("\nInvalid Choice Please Try Again!!\n");
        }
    }

    return 0;
}

void enQueue(){
    if(rear == MAX_SIZE - 1){
        printf("\nQueue is full!!\n");

    }
    else{

        int data;

        if(front == -1){
        front = 0;
        }
        rear++;
        printf("Enter element-->> ");
        scanf("%d",&data);

        Queue[rear] = data;


    }
}

int  dQueue(){
    if(front == -1){
        printf("\nQueue is Empty!!\n");
        return -1;
    }
    else{
        printf("\nDeleted -->> %d ", Queue[front]);

        front++;
        if(front > rear){
            front = rear = -1;
        }
      return 0;
    }
}

void display(){
    if(rear == -1){
        printf("\nQueue is Empty!!\n");
    }
    else{
        printf("\nprint Queue Elements\n");
        int i = rear;
        while(front <= i){
            printf("%d ", Queue[i ]);
            i--;
    



        }
        printf("\n");
    }
}