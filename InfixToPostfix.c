#include <stdio.h>
#include<ctype.h>
#include <stdlib.h> // Header declaration
int stack[20];      // declaring Stack globally
int top = -1;       // declaring top=-1

void push(char x) // push function to insert
{
    stack[++top] = x; // pushing items into stack
}

char pop() // pop function to take out
{
     if (top == -1) // checking if stack is empty
    {
        return 1;
    }
    else
    {
        return stack[top--];
    }
}

int priority(char x) // priority function to give order of preference
{
    if (x == '(') // checking stack items
    {
        return 0; // if stack item is "(" then returns 0
    }
    if (x == '+' || x == '-')
    {
        return 1; // if stack item is "+" or "-" then returns 1
    }
    if (x == '*' || x == '/')
    {
        return 2; // if stack item is "*" or "/" then returns 2
    }
}

int main() // Main function
{
    char exp[20]; // declaring character array
    char *e, x;
    printf("Enter the exp \n");
    scanf("%s", exp); // Taking in expression
    e = exp;
    while (*e != '\0') // while the pointer is'nt 0 execute the given set of statements
    {
        if (isalnum(*e)) // checking if pointer is alphanumeric
        {
            printf("%c", *e);
        }
        else if (*e == '(') // checking if pointer is "("
        {
            push(*e); // push into the stack
        }
        else if (*e == ')') // checking if pointer is ")"
        {
            while ((x = pop()) != '(') // while loop for pop
            {
                printf("%c", x);
            }
        }
        else
        {
            while (priority(stack[top]) >= priority(*e)) // priority checking

                printf("%c", pop());
            push(*e);
        }
        e++;
    }
    while (top != -1) // if stack is not empty pop
    {
        printf("%c", pop());
    }
    return 0;
    printf("\n");
}
