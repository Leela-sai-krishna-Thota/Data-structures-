/*C program to implement operations on Linked List*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node NODE;
void create();
void insertfront(int);
void insertlast(int);
void insertpos(int,int);
void deletefront();
void deletelast();
void deletepos(int);
void display();
NODE *head=NULL;
int main()
{
	int choice,item,pos;
	create();
	while(1)
	{
		printf("\nMENU\n1.Insert Front\n2.Insert Last\n3.Insert at a Specified Postion\n4.Delete Front\n5.Delete Last\n6.Delete at a Specied Postion\n7.Display\n8.Exit\n");
		printf("Enter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("Enter the element to be insert:");
							scanf("%d",&item);
							insertfront(item);
							break;
			case 2: printf("Enter the element to be insert:");
							scanf("%d",&item);
							insertlast(item);
							break;
			case 3: printf("Enter the element to be insert:");
							scanf("%d",&item);
							printf("Enter the position:");
							scanf("%d",&pos);
							insertpos(item,pos);
							break;
			case 4: deletefront();
							break;
			case 5: deletelast();
							break;
			case 6: printf("Enter the position:");
							scanf("%d",&pos);
							deletepos(pos);
							break;
			case 7: display();
							break;
			case 8: exit(0);
							break;
			default: printf("Invalid choice\n");
		}
	}
}
void create()
{
	NODE *cur,*temp;
	char ch;
	int item;
	do
	{
		printf("Enter the element:\n");
		fflush(stdin);
		scanf("%d",&item);
		temp=(NODE *)malloc(sizeof(NODE));
		temp->data=item;
		if(head==NULL)
			head=cur=temp;
		else
		{
			cur->next=temp;
			cur=temp;
		}
		printf("Do you want to continue(y/n):");
		fflush(stdin);
		scanf("%c",&ch);
	}while(ch=='y');
	cur->next=NULL;
}
void insertfront(int item)
{
	NODE *temp;
	temp=(NODE *)malloc(sizeof(NODE));
	temp->data=item;
	temp->next=head;
	head=temp;
}
void insertlast(int item)
{
 NODE *temp, *cur;
 temp = (NODE *)malloc(sizeof(NODE));
 temp->data = item;
 if(head==NULL)
 {
	 head=temp;
 }
 else
 {
		cur=head;
		while(cur->next!=NULL)
 		{
 			cur = cur->next;
 		}
 		cur->next = temp;
		}
		 temp->next = NULL;
}
void insertpos(int item,int pos)
{
 int i;
 NODE *cur=head, *temp;
 if(pos==1) 
 	insertfront(item);
 else
 {
		for(i=1;i<=(pos-2);i++)
	 		cur=cur->next;
	if(cur==NULL)
 		printf("Invalid Position\n");
 	else
	{
	 	temp = (NODE*)malloc(sizeof(NODE));
	 	temp->data = item;
	 	temp->next = cur->next;
		cur->next = temp;
 	}
 }
} 
void deletefront()
{
	NODE *temp;
	if(head==NULL)
	{
 		printf("List is empty\n");
	}
	else
	{
		temp = head;
		head = head->next;
		printf("Element deleted: %d\n",temp->data);
		free(temp);
	}
}
void deletelast()
{
	NODE *temp, *cur;
	if(head==NULL) printf("List is empty\n");
	else if(head->next==NULL)
	{
		temp = head;
		head = NULL;
		printf("Deleted element: %d\n",temp->data);
		free(temp);
	}
	else
	{
		cur = head;
		while(cur->next->next != NULL)
		{
			cur= cur->next;
		}
		temp = cur->next;
		cur->next = NULL;
		printf("Deleted element: %d\n",temp->data);
		free(temp);
	}
} 
void deletepos(int pos)
{
	int i;
  NODE *cur=head,*temp;
  if(pos==1) deletefront();
  else
  {
    for(i=1;i<=(pos-2);i++)
      cur=cur->next;
    if(cur->next == NULL) printf("Invalid Position\n");
    else
    {
      temp = cur->next;
      cur->next = temp->next;
      printf("Deleted element: %d\n",temp->data);
      free(temp);
    }
  }
}
void display()
{
  NODE *temp=head;
  if(head==NULL)
    printf("List is empty\n");
  else
  {
    printf("List content:\n");
   while(temp!=NULL)
   {
     printf("%d ",temp->data);
     temp = temp-> next;
   }
 }
}