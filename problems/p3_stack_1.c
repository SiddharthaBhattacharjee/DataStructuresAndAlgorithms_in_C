// code to implement infix to postfix conversion in c using stack
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 50
char stack[MAX];
int top = -1;
void push(char);
char pop();
int is_operator(char symbol);
int precedence(char symbol);
void InfixToPostfix(char infix_exp[], char postfix_exp[]);
int main()
{
    char infix[MAX], postfix[MAX]; //declare infix string and postfix string
    printf("Enter Infix expression : ");
    gets(infix);
    InfixToPostfix(infix, postfix); //call to convert
    printf("Postfix Expression: ");
    puts(postfix); //print postfix expression
    return 0;
}
void InfixToPostfix(char infix_exp[], char postfix_exp[])
{
    int i, j;
    char item;
    char x;
    push('(');                               //push '(' onto stack
    strcat(infix_exp, ")");                  //add ')' to infix expression
    i = 0;
    j = 0;
    item = infix_exp[i]; //initialize before loop
    while (item != '\0') //run loop till end of infix expression
    {
        if (item == '(')
            push(item);
        else if (isdigit(item) || isalpha(item))
        {
            postfix_exp[j] = item; //add operand symbol to postfix expr
            j++;
        }
        else if (is_operator(item) == 1) // means symbol is operator
        {
            x = pop();
            while (is_operator(x) == 1 && precedence(x) >= precedence(item))
            {
                postfix_exp[j] = x; // so pop all higher precendence operator and
                j++;
                x = pop(); // add them to postfix expresion
            }
            push(x);
            // push current oprerator symbol onto stack
            push(item);
        }
        else if (item == ')') // if current symbol is ')' then
        {
            x = pop(); // pop and keep popping until '(' encounter
            while (x != '(')
            {
                postfix_exp[j] = x;
                j++;
                x = pop();
            }
        }
        else
        { // if current symbol is neither operand not '(' nor ')' and nor operator
            printf("\nInvalid infix Expression.\n"); // the it is illegeal  symbol
            getchar();
            exit(1);
        }
        i++;
        // go to next symbol of infix expression
        item = infix_exp[i];
    } //end while
    if (top > 0)
    {
        printf("Invalid infix Expression.\n"); // the it is illegeal  symbol
        getchar();
        exit(1);
    }
    if (top > 0)
    {
        printf("Invalid infix Expression.\n"); // the it is illegeal  symbol
        getchar();
        exit(1);
    }
    postfix_exp[j] = '\0'; // add sentinel else puts() fucntion will print entire postfix[] array upto MAX size
}
// Function to Return the Precedence of Operator
int precedence(char symbol)
{
    if (symbol == '^') // exponent operator, highest precedence
        return (3);
    else if (symbol == '*' || symbol == '/')
        return (2);
    else if (symbol == '+' || symbol == '-')
        return (1);
    else
        return (0);
}
// Function to verify whether a character is english letter or numeric digit.
// We are assuming in this example that operand will be a single character
int is_operand(char symbol)
{
    if (symbol >= '0' && symbol <= '9')
        return 1;
    else if (symbol >= 'a' && symbol <= 'z')
        return 1;
    else if (symbol >= 'A' && symbol <= 'Z')
        return 1;
    else
        return 0;
}
// Function to verify whether a character is operator symbol or not.
int is_operator(char symbol)
{
    if (symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol == '-')
        return 1;
    else
        return 0;
}
// Function to push an item to stack.
void push(char item)
{
    if (top >= MAX - 1)
    {
        printf("Stack Overflow. \n");
    }
    else
    {
        top = top + 1;
        stack[top] = item;
    }
}
// Function to pop an item from stack.
char pop()
{
    char item;
    if (top < 0)
    {
        printf("Stack Underflow. \n");
        getchar();
        exit(1);
    }
    else
    {
        item = stack[top];
        top = top - 1;
        return (item);
    }
}


