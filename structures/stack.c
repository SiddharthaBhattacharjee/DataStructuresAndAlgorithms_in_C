// code to implement stack operations in c
#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int stack[MAX], top = -1;
void push(int);
int pop();
int peek();
void display();
int main()
{
    int choice, val;
    printf(" 1. Push in stack\n2. Pop from stack\n3. Peek\n4. Display stack\n5. Exit");
    do
    {
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            printf("Enter value to be pushed: ");
            scanf("%d", &val);
            push(val);
            break;
        }
        case 2:
        {
            val = pop();
            if (val != -1)
                printf("The value deleted from stack is: %d", val);
            break;
        }
        case 3:
        {
            val = peek();
            if (val != -1)
                printf("The value stored at top of stack is: %d", val);
            break;
        }
        case 4:
        {
            display();
            break;
        }
        case 5:
        {
            printf("Exit Point ");
            break;
        }
        default:
        {
            printf("Please Enter a Valid Choice(1/2/3/4/5)");
        }
        }
    } while (choice != 5);
    return 0;
}
void push(int val)
{
    if (top == MAX - 1)
        printf("Stack Overflow");
    else
    {
        top++;
        stack[top] = val;
    }
}
int pop()
{
    int val;
    if (top == -1)
    {
        printf("Stack Underflow");
        return -1;
    }
    else
    {
        val = stack[top];
        top--;
        return val;
    }
}
int peek()
{
    if (top == -1)
    {
        printf("Stack is empty");
        return -1;
    }
    else
        return stack[top];
}
void display()
{
    int i;
    if (top == -1)
        printf("Stack is empty");
    else
    {
        for (i = top; i >= 0; i--)
            printf("%d ", stack[i]);
        printf("\n");
    }
}
