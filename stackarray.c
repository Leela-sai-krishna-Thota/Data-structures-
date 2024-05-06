//implementation of stacks using arrays
#include<stdio.h>
#include<stdlib.h>
#define MAX 20
int stack[MAX];
int top=-1;
void push(int);
void pop();
void display();
int main()
{
	while(1)
	{
		int choice,item;
		printf("Menu\n1.push\n2.pop\n3.display\n4.exit\n");
		printf("enter your choice");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("enter the element");
				scanf("%d",&item);
				push(item);
				break;
			case 2:pop();
				break;
			case 3:display();
				break;
			case 4:exit(0);
			default :printf("enter the wrong choice");
		}
	}
	
}
void push(int item)
{
	if(top==MAX-1)
		printf("stack is overflow");
	else
	{
		stack[++top]=item;
		printf("element is inserted");
	}
}
void pop()
{
	if(top==-1)
		printf("stack is underflow");
	else
	{
		printf("deleted element id %d",stack[top--]);
		
	}
}
void display()
{
	if(top==-1)
		printf("stack is empty");
	else
	{
		int i;
		for(i=top;i<=top;i++)
			printf("%d",stack[i]);
	}
}

