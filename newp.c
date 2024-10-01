#include <stdio.h>
#include <string.h>

#define MAX 100


int top = -1;
struct indexMatch{
    char bracket;
    int ind;
};
struct indexMatch stack[MAX];

void push(char c,int index)
{
    if (top == MAX - 1)
    {
        printf("Stack overflow\n");
    }
    else
    {
        stack[++top].bracket = c;
        stack[top].ind=index;
    }
}

struct indexMatch pop()
{
    if (top == -1)
    {
        struct indexMatch empty = {'\0', -1};
        printf("Stack underflow\n");
        
    }
    else
    {
        return stack[top--];
    }
}

int equal(char char1, char char2)
{
    if (char1 == '(' && char2 == ')')
        return 1;
    else if (char1 == '{' && char2 == '}')
        return 1;
    else if (char1 == '[' && char2 == ']')
        return 1;
    else
        return 0;
}

int checking(char *expr,int *closingIndex)
{
    for (int i = 0; i < strlen(expr); i++)
    {
        if (expr[i] == '(' || expr[i] == '{' || expr[i] == '[')
        {

            push(expr[i],i);
        }
        else if (expr[i] == ')' || expr[i] == '}' || expr[i] == ']')
        {
            if (top == -1)
            {
                return 0;
            }
            struct indexMatch topElement = pop();
            if (!equal(topElement.bracket, expr[i]))
            {
                return 0;
            }
            closingIndex[topElement.ind] = i;
        }
    }
    return top == -1;
}

int main()
{
    char expr[MAX];
    int closingIndex[MAX] = {0};

    printf("Enter an expression: ");
    scanf("%s", expr);

    if (checking(expr,closingIndex))
    {
        printf("The expression is valid.\n");
         for (int i = 0; i < strlen(expr); i++) {
            if (closingIndex[i] != 0) {
                printf("Opening bracket at index %d matches closing bracket at index %d\n", i, closingIndex[i]);
            }}
    }
    else
    {
        printf("The expression is not valid.\n");
    }

    return 0;
}