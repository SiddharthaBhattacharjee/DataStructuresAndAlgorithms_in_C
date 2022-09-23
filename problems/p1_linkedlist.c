/*
Problem Statement : code to remove an element (all occurance) and display the linked list
Test Input : 
6
7 9 8 8 4 2
8
Expected Output : 
Linked List:->7->9->4->2
*/

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node* head = NULL;

typedef struct node Node;
void create(){
    int data;
    scanf("%d",&data);
    struct node *n =(Node*) malloc (sizeof(Node));
    n->data = data;
    n->next = NULL;
    if(head == NULL) head = n;
    else{
        struct node *p2 = head;
        while(p2->next !=NULL){
            p2=p2->next;
        }
        p2->next = n;
    }
}

void del(){
    int x;
    scanf("%d",&x);
    struct node *p1 = head;
    while(p1){
        if(p1->data != x) printf("->%d",p1->data);
        p1=p1->next;
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    while(n--) create();
    printf("Linked List:");
    del();
	return 0;
}