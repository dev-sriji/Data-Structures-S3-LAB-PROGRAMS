/**
  * Question
  * Write a menu driven program to perform the following operations on a Doubly Linked List.
  *     i. Insert at the beginning         ii. insert at the end        iii. insert in sorted order
  *     iv. Count the number of nodes      v. reverse the linked list   vi. delete from beginning
  *     vii. Delete from end               viii. display the linked list
  * Compile and Run Command : clear && gcc DoubleeLinkedList.c -o DoubleeLinkedList.out && ./DoubleeLinkedList.out
**/
#include<stdio.h>
#include<stdlib.h>

struct Node {
    struct Node* llink;
    int data;
    struct Node* rlink;
};

void DisplayDLL(struct Node* head){
    if(head->rlink == NULL) {
        printf("The List Is Empty !!");
        return ;
    }
    struct Node* p = head->rlink;
    printf("\n Displaying: \n");
    while(p != NULL){
        printf("%d\t",p->data);
        p=p->rlink;
    }
    printf("\n");
}

int InsertAtBeginning(struct Node* head, int data){
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    temp->data = data;
    temp->rlink = head->rlink;
    temp->llink = head;
    if(head->rlink != NULL){
        (head->rlink)->llink = temp;
    }
    head->rlink = temp;
}

void InsertAtEnd(struct Node* head,int data){
    struct Node* p = head->rlink;
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    while(p!=NULL){
        p=p->rlink;
    }
    temp->rlink = p->rlink;
    temp->data = data;
    temp->llink = p;
    p->rlink = temp;
}

void InsertSorted(struct Node* head, int data) {
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    temp->data = data;
    struct Node* p = head->rlink;
    //pending work
}


void main(){
    struct Node* head = (struct Node*) malloc(sizeof(struct Node));
    if(head == NULL){
        printf("Error Defining Head");
    }
    head->data = 0;
    head->rlink = NULL;
    head->llink = NULL;
    int isExit = 0,data;
    do {
        int op;
        printf("\n1. Insert at the beginning\t2. insert at the end\t\t3. insert in sorted order\n4. Count the number of nodes\t5. reverse the linked list\t6. delete from beginning\n7. Delete from end\t\t8. display the linked list\t9. Exit");
        printf("\nEnter the operation you wanna do : ");
        scanf("%d",&op);
        switch(op){
            case 1:
            printf("Enter The Value To Be Stored : ");
            scanf("%d",&data);
            InsertAtBeginning(head,data);
            break;
            case 2:
            printf("Enter The Value To Be Stored : ");
            scanf("%d",&data);
            InsertAtEnd(head, data);
            break;
            case 3:
            printf("Enter The Value To Be Stored : ");
            scanf("%d",&data);
            InsertSorted(head,data);
            break;
            case 8:
            DisplayDLL(head);
            break;
            case 9:
            printf("Exiting...");
            isExit = 1;
            break;
        }
        printf("Done.\n");
    }while(!isExit);
}
