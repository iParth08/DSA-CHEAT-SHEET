

#include<stdio.h>
#include<stdlib.h>



typedef struct node {
    int data;
    struct node *next;  
} list;




void displayList(list *start){
    
    list *ptr; 

    if(start == NULL){
        printf("\nList is empty...\n");
        return;
    }

    printf("\nPrinting List.... :)\n");
    
    ptr = start;
    
    printf("||");

    while(ptr != NULL){ //until ptr reaches beyond last node
        printf(" %d ||", ptr->data);
        ptr = ptr->next;
    }
    printf("\n\n");
}

list *addAtBeg(list *start, int item){

    list *temp = (list *)malloc(sizeof(list));
    temp->data = item;
    temp->next = start; // temp --> Start[v] --> next
    start = temp;   // Start --> node[V] ---> next

    return start;
}

list *addAtEnd(list *start, int item){

    list *temp = (list *)malloc(sizeof(list));
    temp->data = item;

    //to link, travel till one before end[Null]
    list *iter;
    iter = start;
    while(iter->next != NULL){ //iter  --> [NULL]
        iter = iter->next;
    }
    iter->next = temp; //iter --> temp
    temp->next = NULL;  //iter --> temp --> [NULL]

    return start;
}

list *addAfter(list *start, int data, int item){
    list *temp; //temporary node for memory
    list *ptr; 

    ptr = start;
    //search through the list
    while(ptr != NULL){
        if(ptr->data == data){
            temp = (list *)malloc(sizeof(list)); //create only if desired node is found
            temp->data = item;
            temp->next = ptr->next;
            ptr->next = temp;
            return start; //work done return :: ptr[NODE]-->Added--->next
        }
        ptr = ptr->next;
    }
    
    printf("Such node is not present here.");
    return start; //work not done

}

list *addBefore(list *start, int data, int item){
    list *temp; //temporary node for memory
    list *ptr; //for traversal

    ptr = start;
    //search through the list
    while(ptr != NULL){
        if(ptr->next->data == data){
            temp = (list *)malloc(sizeof(list)); //create only if desired node is found
            temp->data = item;
            temp->next = ptr->next; //here, ptr is one node before the DESIRED node 
            ptr->next = temp;
            return start; //work done return  :: ptr --> ADDED --> [NODE]
        }
        ptr = ptr->next;
    }
    //if desired node not present, 
    printf("Such node is not present here.");
    return start; //work not done

}

list *addAtPos(list *start, int pos, int item){
    list *temp, *ptr;
    
    if(pos == 1){
        start = addAtBeg(start, item);
        return start;
    }

    ptr = start;
    for(int i=1; i<pos-1 && ptr != NULL; i++){
        ptr = ptr->next;
    }

    if(ptr == NULL){
        printf("That pos is beyond reach at the moment.");
        return start;
    }
    else{
        temp = (list *)malloc(sizeof(list));
        temp->data = item;

        temp->next = ptr->next;
        ptr->next = temp;
    }
    return start;
}

list *delNode(list *start, int data){
    list *temp, *ptr;

    //if list is already empty
    if(start == NULL){
        printf("List is empty...:)\n");
        return start;
    }

    //delete first node, reassign head
    if(start->data == data){
        temp = start; //start total copied to temp, data&next[memory]
        start = start->next;

        free(temp);
        return start;
    }

    //delete any node including END
    ptr = start; //for going to node
    while(ptr->next != NULL){
        if(ptr->next->data == data){
            temp = ptr->next; //node stored for deletion
            ptr->next = temp->next; //ptr->next = ptr->next->next

            free(temp);
            return start;
        }

        ptr = ptr->next; //never forget
    }

    //in caseno node match the data
    printf("No such node present....");
    return start;
}

list *reverseNode(list *start){
    list *prev, *nxt, *ptr;
    prev = NULL;
    nxt = NULL;

    ptr = start;
    //for(int i=0; i<size; i++)
    while(ptr != NULL){
        //reverse sequence by breaking-formimg links
        nxt = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = nxt;
 
    }
    start = prev;
    return start;
}

list *createList(list *start){
    int size, items;

    printf("\nList Creation in Progress..... :)\n");
    printf("Enter no of nodes : ");
    scanf("%d", &size);

    start = NULL; //list initialized.

    //no nodes
    if(size == 0) return start;

    //creation of first element
    printf("Enter 1st element [head] : ");
    scanf("%d", &items);
    start = addAtBeg(start, items);

    //rest of nodes added to list
    printf("Add other nodes....\n");
    for(int i=2; i<=size; i++){
        scanf("%d", &items);
        start = addAtEnd(start, items); 
        //every next node added at the end of list

    }

    return start;

}



//ALERT:: Main Driver

int main(){
    list *head = NULL; //nothingness at the begin
    int item, pos, data;

    printf("L\tI\tN\tK\tE\tD \t\t  L\tI\tS\tT\n\n");
    head = createList(head);
    displayList(head);

    printf("Enter 1st [head] node : ");
    scanf("%d", &item);
    head = addAtBeg(head, item);
    displayList(head);

    printf("Enter END node : ");
    scanf("%d", &item);
    head = addAtEnd(head, item);
    displayList(head);

    printf("Add after node............\n");
    printf("Enter node [data] : ");
    scanf("%d", &data);
    printf("Enter item to add after that node : ");
    scanf("%d", &item);
    head = addAfter(head, data, item);
    displayList(head);

    printf("Add before node............\n");
    printf("Enter node [data] : ");
    scanf("%d", &data);
    printf("Enter item to add before that node : ");
    scanf("%d", &item);
    head = addBefore(head, data, item);
    displayList(head);

    printf("Add at Position............\n");
    printf("Enter position to add at : ");
    scanf("%d", &pos);
    printf("Enter item to add : ");
    scanf("%d", &item);
    head = addAtPos(head, pos, item);
    displayList(head);

    printf("Enter data to delete that node : ");
    scanf("%d", &data);
    delNode(head, data);
    displayList(head);

    printf("Reversing the Array..... \n");
    head = reverseNode(head);
    displayList(head);


}
