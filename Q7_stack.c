#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX_SIZE 5

int top = -1;

int stack[MAX_SIZE]; // Initializing the stack using an array

//function initialise
void push();
int pop();
int peek();
bool isEmpty();
bool isFull();

int main(){

    int choice;
    printf("Choose the following operation-->> \n");
    printf("\n 0. Exit \t 01. Push \t 02. Pop \t 03. Peek \t 04. IsEmpty \t 05. IsFull \n \n");

    while(1){

     printf(" Choice-->> ");
     scanf("%d", &choice);

     switch (choice)
     {
     case 0: exit(0);
     case 1: push(); break;
     case 2: pop();  break;
     case 3: peek();break;
     case 4: 
     if(isEmpty()){
       printf("\nStack is Empty..!!\n");

     }else{
        printf("\n Stack is not Empty..!!\n");
     }
     break;
     case 5: 
     if(isFull()){
        printf("\nStack is Full..\n");

     }else{
        printf("\nNo Stack is not full..\n");
     }
     break;
     
     default:printf("\n<<<<-----Invalid choice Try Again!!!!-->>>>>\n");
        
     }

    }
    
    return 0;

}

void push(){
    int item;
    if(isFull()){
        printf("\n Stack is Overflow \n");
    }
    else{
        printf("\nEnter Element-->> ");
        scanf("%d", &item);
        top += 1;
        stack[top] = item;
    }

}

int pop(){

    if(isEmpty()){
        printf("\nStack is Underflow\n");
    }
    else{
        int item = stack[top];
        printf("\nPopping %d out of the stack\n", item);
        top -= 1;
        return 0;

    }
    return -1;

}

int peek(){
    int item = stack[top];
    printf("\nPeek element of Stack is %d \n", item);

    return item;

}

bool isEmpty(){
    if(top == -1){
        return true;
    }
    else{
        return false;
    }

}

bool isFull(){

    if(top == MAX_SIZE - 1){
        return true;
    }
    else{
        return false;
    }

}
