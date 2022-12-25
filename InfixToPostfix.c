// Program of infix to postfix

#include <stdio.h>
void infix_to_postfix();
void push(char);
char pop();
int priority(char);
char infix[30], postfix[30], stack[30];
int top = -1;

void main()
{
    printf("enter valid infix expression\n");
    scanf("%s", infix);
    infix_to_postfix();
    printf("infix expression is %s\n", infix);
    printf("postfix expression is %s\n", postfix);
}

void push(char item) // push the incoming operator onto the stack

{
    top = top + 1;
    stack[top] = item;
}

char pop() // pop the stack and print the operators
{
    return stack[top--];
}

int priority(char symbol)
{
    int p;
    switch (symbol) // using switch
    {
    case '+':
    case '-':
        p = 1;
        break;
    case '*':
    case '/':
    case '%':
        p = 2;
        break;
    case '^':
    case '$':
        p = 3;
        break;
    case '(':
    case ')':
        p = 0;
        break;
    case '#':
        p = -1;
        break;
    }
    return p;
}

void infix_to_postfix()
{
    int i = 0, j = 0;
    char symbol, temp;
    push('#');
    for (i = 0; infix[i] != '\0'; i++)
    {
        symbol = infix[i];
        switch (symbol)
        {
        case '(':
            push(symbol);
            break;
        case ')':
            temp = pop();
            while (temp != '(')
            {
                postfix[j] = temp;
                j++;
                temp = pop();
            }
            break;
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
        case '^':
        case '$':
            while (priority(stack[top]) >= priority(symbol))
            {
                temp = pop();
                postfix[j] = temp;
                j++;
            }
            push(symbol);
            break;
        default:
            postfix[j] = symbol;
            j++;
        }
    }
    while (top > 0)
    {
        temp = pop();
        postfix[j] = temp;
        j++;
    }
    postfix[j] = '\0';
}
