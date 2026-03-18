#include<stdio.h>
#define N 5
int Queue[N];
int front =  -1;
int rear = -1;
int count = 0;

void enqueue()
{
	int x;
	if(front==(rear+1)%N)
	{
		printf("queue is full");
		return;
	}
	printf("Enter the data to insert : ");
	scanf("%d",&x);
	if(front == -1)
		front=0;
	rear=(rear+1)%N;
	Queue[rear]=x;
	count++;
	printf("%d is enqueued..");
}

void dequeue()
{
	if(front==-1)
	{
		printf("Queue is empty..");
		return;
	}
	printf("%d is deleted from the queue..",Queue[front]);
	if(front==rear)
		front=rear=-1;
	else
		front=(front+1%N);
	count--;
}

void display()
{
	if(front==-1)
	{
		printf("Queue is empty..");
		return;
	}
	printf("Quueue elements are :");
	i = front;
	while(1)
	{
		printf("%d",Queue[i]);
		if(i==rear)
			break;
		i=(i+1)%N;
	}
}

void main()
{
	
}
