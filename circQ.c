#include <stdio.h>
int front = -1, rear = -1;
void enqueue(int a[],int n, int item){
	if((rear+1)%n==front)
		printf("Queue Full");
	else if(front == -1 && rear == -1){
		front = 0; 
		rear = 0;
		a[rear] = item;
	}
	else{
		rear = (rear+1)%n;
		a[rear] = item;
	}
}
void dequeue(int a[], int n){
	if(front == -1 && rear == -1)
		printf("Queue Empty");
	else if(front == rear){
		front = -1;
		rear = -1;
	}
	else
		front = (front+1)%n;
}
void main(){
	printf("Enter size of queue: ");
	int size;
	scanf("%d", &size);
	int S[size];
	int choice; 
	menu:
	printf("Enter the action you want to do:\n1 - Enter an integer\n2- Remove the top integer\n3- Exit\n");
	scanf("%d",&choice);
	switch(choice){
		case 1:
			printf("Enter number you want to add\n");
			int num;
			scanf("%d",&num);
			enqueue(S,size,num);
			goto menu;
			break;
		case 2:
			dequeue(S, size);
			goto menu;
			break;
		case 3:
			return;
	}
}