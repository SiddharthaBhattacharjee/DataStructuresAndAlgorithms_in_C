// code to implement infix to prefix conversion in c using stack

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
void InfixToPrefix(char infix_exp[], char prefix_exp[]);
int main()
{
    char infix[MAX], prefix[MAX]; //declare infix string and prefix string
    printf("Enter Infix expression : ");
    gets(infix);
    InfixToPrefix(infix, prefix); //call to convert
    printf("Prefix Expression: ");
    puts(prefix); //print prefix expression
    return 0;
}
void InfixToPrefix(char infix_exp[], char prefix_exp[])
{
    int i, j;
    char item;
    char x;
    strrev(infix_exp);
    for (i = 0; infix_exp[i] != '\0'; i++)
    {
        if (infix_exp[i] == '(')
        {
            infix_exp[i] = ')';
            i++;
        }
        else if (infix_exp[i] == ')')
        {
            infix_exp[i] = '(';
            i++;
        }
    }
    push(')');                               //push ')' onto stack
    strcat(infix_exp, "(");                  //add '(' to infix expression
    i = 0;
    j = 0;
    item = infix_exp[i]; //initialize before loop
    while (item != '\0') //run loop till end of infix expression
    {
        if (item == ')')
            push(item);
        else if (isdigit(item) || isalpha(item))
        {
            prefix_exp[j] = item; //add operand symbol to prefix expr
            j++;
        }
        else if (is_operator(item) == 1) // means symbol is operator
        {
            x = pop();
            while (is_operator(x) == 1 && precedence(x) >= precedence(item))
            {
                prefix_exp[j] = x; // so pop all higher precendence operator and
                j++;
                x = pop(); // add them to prefix expresion
            }
            push(x);
            // push current oprerator symbol onto stack
            push(item);
        }
        else if (item == '(') // if current symbol is '(' then
        {
            x = pop(); // pop and keep popping until ')' encounter
            while (x != ')')
            {
                prefix_exp[j] = x;
                j++;
                x = pop();
            }
        }
        i++;
        item = infix_exp[i]; //go to next symbol of infix expression
    }
    if (top > 0)
    {
        printf("Invalid infix Expression.\n");
        exit(1);
    }
    if (top > 0)
    {
        printf("Invalid infix Expression.\n");
        exit(1);
    }
    prefix_exp[j] = '\0'; //add sentinel else puts() fucntion will print entire postfix[] array upto MAX size
    strrev(prefix_exp);
}
int is_operator(char symbol)
{
    if (symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol == '-')
        return 1;
    else
        return 0;
}
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
void push(char item)
{
    if (top >= MAX - 1)
    {
        printf("Stack Overflow \n");
        exit(1);
    }
    else
    {
        top = top + 1;
        stack[top] = item;
    }
}
char pop()
{
    char item;
    if (top < 0)
    {
        printf("Stack Underflow \n");
        exit(1);
    }
    else
    {
        item = stack[top];
        top = top - 1;
        return (item);
    }
}

