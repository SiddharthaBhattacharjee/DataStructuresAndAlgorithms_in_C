/*
Problem Statement : Code to take a linked list, display it and then display the folded linked list

Sample Input: 
16
1 3 4 7 9 11 13 14 18 19 23 24 56 32 98 17

Expected Output:
Link list data:1 3 4 7 9 11 13 14 18 19 23 24 56 32 98 17 
Link list data after fold:1 17 3 98 4 32 7 56 9 24 11 23 13 19 14 18 
*/

#include <iostream> 
using namespace std;
//constructing the structure of a node
struct node
{
	int data;
	struct node *next;
};

void create(struct node **head,int data) 
{
	struct node *n =(node*) malloc (sizeof(node));
    n->data = data;
    n->next = NULL;
    struct node *temp = *head;
    while(temp->next !=NULL){
        temp = temp->next;
    }
    temp->next = n;
}
void print(struct node *head) 
{
	struct node* ptr = head;
	while (ptr)
	{
		cout<<ptr->data <<" ";
		ptr = ptr->next;
	}
}

struct node* newNode(int data)//allocating memory to a new node(dummy node)
{
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

//function for reversing the List
void reverselist(node** head) 
{ 
    node *prev = NULL, *curr = *head, *next; 
  
    while (curr) { 
        next = curr->next; 
        curr->next = prev; 
        prev = curr; 
        curr = next; 
    } 
  
    *head = prev; 
}

void fold(node** head) //function for rearranging the node
{ 
    cout<<"Link list data:";	
    print(*head);
    node *slow = *head, *fast = slow->next; 
    while (fast && fast->next) { 
        slow = slow->next; 
        fast = fast->next->next; 
    } 
    struct node* head1 = *head; 
    struct node* head2 = slow->next; 
    slow->next = NULL;//slow pointer will be at middle position 

    reverselist(&head2);//reversing second half of the list 
  
   
    *head = newNode(0); // Assign dummy Node 
  
    node* curr = *head; 
    while (head1 || head2) { 
        if (head1) { 
            curr->next = head1; 
            curr = curr->next; 
            head1 = head1->next; 
        } 
  
        if (head2) { 
            curr->next = head2; 
            curr = curr->next; 
            head2 = head2->next; 
        } 
    } 
  
    *head = (*head)->next; 
    cout<<"\nLink list data after fold:";
    print(*head);
} 

int main(void)//main method.
{
    int n,t;
	cin>>n;
	cin>>t;
	--n;
	struct node* head = newNode(t);
	while(n--){ cin>>t; create(&head, t);}

	fold(&head);

	return 0;
}