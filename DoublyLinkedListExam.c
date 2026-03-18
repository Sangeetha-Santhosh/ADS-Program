#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *prev,*next;
}N;

N *head = NULL;
N *tail = NULL;
int count=0;

N *create(int x)
{
	N *new=(N*)malloc(sizeof(N));
	new -> data = x;
	new -> prev = NULL;
	new -> next = NULL;
	return new;
}

void insertbeg()
{
	int x;
	printf("Enter the data to insert at begining : ");
	scanf("%d",&x);
	N *new = create(x);
	if(head==NULL && tail==NULL)
		head=tail=new;
	else
	{
		new->next=head;
		head->prev=new;
		head=new;
	}
	printf("%d is inserted at the begining..",x);
	count++;	
}

void insertend()
{
	int x;
	printf("Enter the data to insert at end : ");
	scanf("%d",&x);
	N *new = create(x);
	if(head==NULL && tail==NULL)
		head=tail=new;
	else
	{
		new->prev=tail;
		tail->next=new;
		tail=new;
	}
	printf("%d is inserted at the end..",x);
	count++;
}

void delbeg()
{
	if(head==NULL && tail==NULL)
	{
		printf("List is empty...");
		return;
	}
	N *temp=head;
	printf("%d is deleted from the begining : ",temp->data);
	if(head==tail)
		head=tail=NULL;
	else
	{
		head = head->next;
		head->prev=NULL;
	}
	free(temp);
	count--;
}

void delend()
{
	if(head==NULL && tail==NULL)
	{
		printf("List is empty...");
		return;
	}
	N *temp=tail;
	printf("%d is deleted from the end.. ",temp->data);
	if(head==tail)
		head=tail=NULL;
	else
	{
		tail = tail->prev;
		tail->next=NULL;
	}
	free(temp);
	count--;
}

void travbeg()
{
	if(head==NULL && tail==NULL)
	{
		printf("List is empty...");
		return;
	}
	N *temp=head;
	printf("Traaversal from begining\n");
	printf("NULL");
	while(temp!=NULL)
	{
		printf("<-%d->",temp->data);
		temp=temp->next;
	}
	printf("NULL");
}

void travend()
{
	if(head==NULL && tail==NULL)
	{
		printf("List is empty...");
		return;
	}
	N *temp=tail;
	printf("Traaversal from end\n");
	printf("NULL");
	while(temp!=NULL)
	{
		printf("<-%d->",temp->data);
		temp=temp->prev;
	}
	printf("NULL");
}

void main()
{
	int ch;
	while(1)
	{
		printf("operations\n1.insertbeg\n2.insertend\n3.deletebeg\n4.deleteend\n5.travbeg\n6.trvaend\n7.count\n8.exit\nEnter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 :insertbeg(); break;
			case 2 :insertend(); break;
			case 3 :delbeg(); break;
			case 4 :delend(); break;
			case 5 :travbeg(); break;
			case 6 :travend(); break;
			case 7 :printf("Count of node is %d",count);break;
			case 8 :printf("Exiting...");
					exit(0);
					break;
			}	
	}
}
