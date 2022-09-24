#include <stdio.h>
#include <stdlib.h>

// Structure of a single node of linked list
struct Node{
    int data;
    struct Node* next;
};

typedef struct Node node;
int len=0;

//base address or starting point of linked list

node* getNode(node** start,int data){
    node* newnode = (node*) malloc (sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

// To initialise or create a linked list for a given n no. of data 
void createLinkedList(node** start,int n,int arr[]){
    int i;
    node *newnode, *temp;
    while(--n){
        newnode = getNode(start,arr[i]);
        if(*start == NULL) *start = newnode;
        else{
            temp = *start;
            while(temp->next!=NULL){
                temp = temp->next;
            }
            temp->next = newnode;
        }
        len++;
    }
}

// To insert a node to the start of the linked list
void insertStart(node** start,int data){
    node *newnode;
    newnode = getNode(start,data);
    if(*start == NULL) *start = newnode;
    else{
        newnode->next = *start;
        *start = newnode;
    }
    len++;

}

// To insert a node to the end of the Linked list
void insertEnd(node** start,int data){
    node *newnode, *temp;
    newnode = getNode(start,data);
    if(*start == NULL) *start = newnode;
    else{
        temp = *start;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = newnode;
    }
    len++;
}

// To insert a node to a given index position
void insertPos(node** start,int data,int pos){
    if(pos>len){
        printf("Index out of bound");
    }
    else{
        node* temp = *start;
        node* newnode = getNode(start,data);
        for(int i=0;i<pos;i++){
            temp = temp->next;
        }
        node* temp2 = temp->next;
        temp->next = newnode;
        newnode->next = temp2;
    }
}

// To insert a node in a sorted Linked list in appropriate position
void insertSorted(node** start,int data){
    node* newnode = getNode(start,data);
    node* temp = *start;
    if(*start == NULL) *start = newnode;
    else{
        while(temp->next!=NULL && temp->data < data){
            temp = temp->next;
        }
        node* temp2 = temp->next;
        temp->next = newnode;
        newnode->next = temp2;
    }
}

//deletes the 1st occurence of the element from linked list
void deleteByElement(node** start,int data){
    node* temp = *start;
    node* temp2 = temp->next;
    while(temp2->next != NULL){
        if(temp2->data == data){
            temp->next = temp2->next;
            free(temp2);
            len--;
            return;
        }
        temp = temp->next;
        temp2 = temp->next;
    }
    if(temp2->data == data){
        temp->next = NULL;
        free(temp2);
        len--;
    }
}

// Deletes the element at the position given
void deleteByPosition(node** start,int pos){
    if(pos>len){
        printf("Index out of bound!");
        return;
    }
    node* temp = *start;
    for(int i=0;i<pos;i++){
        temp = temp->next;
    }
    node *temp2 = temp->next;
    temp->next = temp2->next;
    free(temp2);
    len--;
}

// Searches and returns the position of 1st occurance of an element in the linked list, returns -1 if element is not in linked list
int search(node** start,int data){
    node* temp = *start;
    int pos = 0;
    while(temp){
        if(temp->data == data){
            return pos;
        }
        temp = temp->next;
        pos++;
    }
    return -1;
}

// To display a visual representation of the linked list
void displayLinkedList(node** start){
    printf("\nStart->");
    node* temp = *start;
    while(temp){
        printf("%d->",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(){
    node ** start = NULL;
    int initial[] = {2,3,4,6,7,9};
    createLinkedList(start,6,initial);
    displayLinkedList(start);
    insertStart(start,1);
    displayLinkedList(start);
    insertEnd(start,10);
    displayLinkedList(start);
    insertPos(start,5,4);
    displayLinkedList(start);
    insertSorted(start,8);
    displayLinkedList(start);
    deleteByElement(start,3);
    displayLinkedList(start);
    deleteByPosition(start,1);
    displayLinkedList(start);
    return 0;
}
