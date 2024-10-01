#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int value) {
    if ((front == 0 && rear == MAX - 1) || (rear == (front - 1) % (MAX - 1))) {
        printf("Queue overflow\n");
        return;
    }

    if (front == -1) {
        front = rear = 0;
    } else if (rear == MAX - 1 && front != 0) {
        rear = 0;
    } else {
        rear++;
    }

    queue[rear] = value;
    printf("Enqueued %d into the queue\n", value);
}

int dequeue() {
    if (front == -1) {
        printf("Queue underflow\n");
        return -1;
    }

    int value = queue[front];
    queue[front] = -1;

    if (front == rear) {
        front = rear = -1; 
    } else if (front == MAX - 1) {
        front = 0;
    } else {
        front++;
    }

    printf("Dequeued %d from the queue\n", value);
    return value;
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements are:\n");
    if (rear >= front) {
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    } else {
        for (int i = front; i < MAX; i++) {
            printf("%d ", queue[i]);
        }
        for (int i = 0; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\nQueue Operations: 1. Enqueue 2. Dequeue 3. Display 4. Exit \nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }

    return 0;
}