#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node NODE;
void push();
void pop();
void display();
NODE *head=NULL;
int main()
{
	int item,ch;
	while(1)
	{
		printf("1.push\n");
		printf("2.pop\n3.display\n4.exit\n");
		printf("enter your choice:\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:	printf("enter element to be inserted:\n");
				scanf("%d",&item);
				push(item);
				break;
			case 2:	pop();
				break;
			case 3:	display();
				break;
			case 4:	exit(0);
			default:printf("enter the invalid choice\n");
		}
	}
}

void push(int item)
{
	NODE *temp;
	temp=(NODE *)malloc(sizeof(NODE));
	temp->data=item;
	temp->next=head;
	head=temp;
}	

void pop()
{
	NODE *temp;
	if(head==NULL)
		printf("stack underflow\n");
	else
	{
		temp=head;
		head=head->next;
		printf("deleted element :%d\n",temp->data);
		free(temp);
	}	
}

void display()
{
	NODE *temp=head;
	if(head==NULL)
		printf("stack  is empty:\n");
	else
	{
		printf("stack content:\n");
		while(temp!=NULL)
		{
			printf("%4d",temp->data);
			temp=temp->next;
		}
	}	
}

