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
node ** start = NULL;

node* getNode(int data){
    node* newnode = (node*) malloc (sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

// To initialise or create a linked list for a given n no. of data 
void createLinkedList(int n,int arr[]){
    int i;
    node *newnode, *temp;
    while(--n){
        newnode = getNode(arr[i]);
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
void insertStart(int data){
    node *newnode;
    newnode = getNode(data);
    if(*start == NULL) *start = newnode;
    else{
        newnode->next = *start;
        *start = newnode;
    }
    len++;

}

// To insert a node to the end of the Linked list
void insertEnd(int data){
    node *newnode, *temp;
    newnode = getNode(data);
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
void insertPos(int data,int pos){
    if(pos>len){
        printf("Index out of bound");
    }
    else{
        node* temp = *start;
        node* newnode = getNode(data);
        for(int i=0;i<pos;i++){
            temp = temp->next;
        }
        node* temp2 = temp->next;
        temp->next = newnode;
        newnode->next = temp2;
    }
}

// To insert a node in a sorted Linked list in appropriate position
void insertSorted(int data){
    node* newnode = getNode(data);
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
void deleteByElement(int data){
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
void deleteByPosition(int pos){
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
int search(int data){
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
void displayLinkedList(){
    printf("\nStart->");
    node* temp = *start;
    while(temp){
        printf("%d->",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(){
    int initial[] = {2,3,4,6,7,9};
    createLinkedList(6,initial);
    displayLinkedList();
    insertStart(1);
    displayLinkedList();
    insertEnd(10);
    displayLinkedList();
    insertPos(5,4);
    displayLinkedList();
    insertSorted(8);
    displayLinkedList();
    deleteByElement(3);
    displayLinkedList();
    deleteByPosition(1);
    displayLinkedList();
    return 0;
}
