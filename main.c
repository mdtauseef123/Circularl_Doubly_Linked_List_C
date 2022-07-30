#include<stdio.h>
#include<stdlib.h>

//Defining the structure of the node
struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
};


//Defining the global head and tail pointer
struct Node *head=NULL,*tail=NULL;


//Inserting node at the end of the linked list
void insertAtEnd(int num){
    struct Node *newNode;
    newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=num;
    if(head==NULL){
        newNode->prev=newNode->next=newNode;
        head=tail=newNode;
    }
    else{
        head->prev=newNode;
        tail->next=newNode;
        newNode->prev=tail;
        newNode->next=head;
        tail=newNode;
    }
}


//Inserting node at the front of the linked list
void insertAtFront(int num){
    struct Node *newNode;
    newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=num;
    if(head==NULL)
        head=tail=newNode->prev=newNode->next=newNode;
    else{
        newNode->next=head;
        newNode->prev=tail;
        tail->next=newNode;
        head->prev=newNode;
        head=newNode;
    }
}


//Inserting node at a given index
void insertAtPosition(int num,int pos){
    struct Node *newNode;
    newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=num;
    if(pos==1){
        newNode->next=head;
        newNode->prev=tail;
        tail->next=newNode;
        head->prev=newNode;
        head=newNode;
    }
    else{
        struct Node *temp=head;
        int k=pos-2;
        while(k--){
            temp=temp->next;
        }
        newNode->prev=temp;
        newNode->next=temp->next;
        temp->next->prev=newNode;
        temp->next=newNode;
        if(pos==getLength())
            tail=newNode;
    }
}


//Inserting node after a given node
void insertAfterNode(struct Node *pos,int num){
    struct Node *newNode;
    newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=num;
    struct Node *afterNode=pos->next;
    newNode->prev=pos;
    newNode->next=afterNode;
    pos->next=newNode;
    afterNode->prev=newNode;
}


//Deleting the specified node
void deleteNode(struct Node *delNode){
    if(delNode==head){
        int x=delNode->data;
        head=head->next;
        head->prev=tail;
        tail->next=head;
        free(delNode);
        printf("%d is deleted successfully\n",x);
    }
    else if(delNode==tail){
        int x=delNode->data;
        tail=tail->prev;
        tail->next=head;
        head->prev=tail;
        free(delNode);
        printf("%d is deleted successfully\n",x);
    }
    else{
        int x=delNode->data;
        struct Node *prevNode=delNode->prev;
        struct Node *afterNode=delNode->next;
        prevNode->next=afterNode;
        afterNode->prev=prevNode;
        free(delNode);
        printf("%d is deleted successfully\n",x);
    }
}


//Deleting the node at a given position
void deleteNodeAt(int pos){
    struct Node *delNode;
    if(pos==1){
        int len=getLength();
        delNode=head;
        int x=delNode->data;
        head=head->next;
        head->prev=tail;
        tail->next=head;
        free(delNode);
        if(len==1)
            head=tail=NULL;
        printf("%d is deleted successfully\n",x);
    }
    else if(delNode==tail){
        int len=getLength();
        delNode=tail;
        int x=delNode->data;
        tail=tail->prev;
        tail->next=head;
        head->prev=tail;
        free(delNode);
        if(len==1)
            head=tail=NULL;
        printf("%d is deleted successfully\n",x);
    }
    else{
        pos--;
        delNode=head;
        while(pos--)
            delNode=delNode->next;
        int x=delNode->data;
        struct Node *prevNode=delNode->prev;
        struct Node *afterNode=delNode->next;
        prevNode->next=afterNode;
        afterNode->prev=prevNode;
        free(delNode);
        printf("%d is deleted successfully\n",x);
    }
}


//Displaying the node in forward direction
void displayForward(){
    if(head==NULL){
        printf("Empty List!\nNothing can be printed.");
        return;
    }
    struct Node *temp=head;
    do{
        printf("%d->",temp->data);
        temp=temp->next;
    }while(temp!=head);
    printf("NULL\n");
}


//Displaying the node in backward direction
void displayBackward(){
    struct Node *temp=tail;
    do{
        printf("%d->",temp->data);
        temp=temp->prev;
    }while(temp!=tail);
    printf("NULL\n");
}


//Getting the length of the list
int getLength(){
    struct Node *temp=head;
    int cnt=0;
    do{
        cnt++;
        temp=temp->next;
    }while(temp!=head);
    return cnt;
}


int main(){
    insertAtEnd(1);
    insertAtEnd(2);
    insertAtEnd(3);
    insertAtEnd(4);
    insertAtPosition(5,5);
    displayForward();
    insertAfterNode(head->next,9);
    displayForward();
    displayBackward();
    return 0;
}
