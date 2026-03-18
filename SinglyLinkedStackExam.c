#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node* next;
}N;

N *top=NULL;

void push()
{
	int x;
	printf("Enter the element to push : ");
	scanf("%d",&x);
	N *new = (N*)malloc(sizeof(N));
	new->data=x;
	new->next=top;
	top=new;
	printf("%d pushed successfully ..",x);
}

void pop()
{
	if (top==NULL)
		printf("Stack is Empty...");
	else
	{
		printf("%d popped successfully",top->data);
		N *temp=top;
		top=top->next;
		free(temp);
	}
}

void display()
{
	if (top==NULL)
		printf("Stack is Empty...");
	else
	{
		N *temp=top;
		printf("Stack elements are :\n");
		while(temp!=NULL)
		{
			printf("\n|   %d   |",temp->data);
			temp=temp->next;
		}
		printf("NULL");
	}
}

void peek()
{
	if (top==NULL)
		printf("Stack is Empty...");
	else
		printf("Top element is : %d",top->data);
}

void count()
{
	int c=0;
	if (top==NULL)
		printf("Stack is Empty...");
	else
	{
		
		N *temp=top;
		while(temp!=NULL)
		{
			c++;
			temp=temp->next;
		}
		printf("Count is %d",c);
	}
}

void main()
{
	int ch;
	while(1)
	{
		printf("operations\n1.push\n2.pop\n3.peek\n4.count\n5.exit\nEnter your choice :");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 :push(); break;
			case 2 :pop(); break;
			case 3 :peek(); break;
			case 4 :count(); break;
			case 5 :display();break;
			case 6 :exit(0);
		}
	}
}
