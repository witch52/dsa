#include <stdio.h>
#define MAX 2

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int value)
{
    if ((front == 0 && rear == MAX - 1) || (rear == (front - 1) % (MAX - 1)))
    {
        printf("Queue overflow\n");
    }
    else
    {
        if (front == -1)
        {
            front = rear = 0;
        }
        else if (rear == MAX - 1 && front != 0)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
        queue[rear] = value;
        printf("Enqueued %d into the queue\n", value);
    }
}

int dequeue()
{
    if (front == -1)
    {
        printf("Queue underflow\n");
        return -1;
    }

    int value = queue[front];
    queue[front] = -1;

    if (front == rear)
    {
        front = rear = -1;
    }
    else if (front == MAX - 1)
    {
        front = 0;
    }
    else
    {
        front++;
    }

    printf("Dequeued %d from the queue\n", value);
    return value;
}

void display()
{
    if (front == -1)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements are:\n");
    if (rear >= front)
    {
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
    }
    else
    {
        for (int i = front; i < MAX; i++)
        {
            printf("%d ", queue[i]);
        }
        for (int i = 0; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
    }
    printf("\n");
}

int main()
{
    int a, b, y = 1;
    while (y == 1)
    {
        printf("To enqueue Enter 1 , To dequeue Enter 2 ,to display the queue Enter anything else ");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            printf("Enter number to enqueued ");
            scanf("%d", &b);
            enqueue(b);
            break;
        case 2:
            dequeue();
            break;

        default:
            display();
            break;
        }
        printf("Want to continue ? enter 1 ,else enter anything else ");
        scanf("%d", &y);
    }

    return 0;
}