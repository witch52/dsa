#include <stdio.h>
#define MAX 5

int stack[MAX]; 
int top = -1;

void push(int item)
{
    if (top == MAX - 1)
    {
        printf("Overflow\n");
    }
    else
    {
        stack[++top] = item;
        printf("Pushed %d into the stack\n", item);
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Underflow\n");
    }
    else
    {
        printf("Item popped: %d\n", stack[top--]);
    }
}

void peek()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Top element is: %d\n", stack[top]);
    }
}

void display()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack elements are:\n");
        for (int i = top; i >= 0; i--)
        {
            printf("%d\t", stack[i]);
        }
        printf("\n");
    }
}

int isFull()
{
    return top == MAX - 1;
}

int isEmpty()
{
    return top == -1;
}

int main()
{
    int choice, value, y = 1;

    while (y == 1)
    {
        printf("Choose an operation: 1. Push  2. Pop  3. Peek  4. IsFull  5. IsEmpty and any other number to display the current stack\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            if (isFull())
            {
                printf("Stack is full\n");
            }
            else
            {
                printf("Stack is not full\n");
            }
            break;
        case 5:
            if (isEmpty())
            {
                printf("Stack is empty\n");
            }
            else
            {
                printf("Stack is not empty\n");
            }
            break;
        default:
            display();
            break;
        }

        printf("Want to continue? Enter 1 for Yes, any other number for No: ");
        scanf("%d", &y);
    }

    return 0;
}