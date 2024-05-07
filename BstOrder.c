//c programe to implement the binary search tree using recursion
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *lchild,*rchild;
};
typedef struct node NODE;
NODE*root=NULL;
NODE* insert(NODE*,int);
void inorder(NODE*);
void preorder(NODE*);
void postorder(NODE*);
int main()
{
	int choice,item;
	while(1)	
	{
		printf("****MENU****\n");
		printf("1.insert\n2.inorder\n3.preorder\n4.postorder\n5.exit\n");
		printf("enter your choice");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("enter the element");
				scanf("%d",&item);
				root=insert(root,item);
				break;
			case 2:inorder(root);
				break;
			case 3:preorder(root);
				break;
			case 4:postorder(root);
				break;
			case 5:exit(0);
			default :printf("invalid choice");
		}
	}
}
NODE*insert(NODE*root,int item)
{
	if(root==NULL)
	{
		root=(NODE*)malloc(sizeof(NODE));
		root->data=item;
		root->lchild=root->rchild=NULL;
	}
	else
	{
		if(item>root->data)
			root->rchild=insert(root->rchild,item);
		else
			root->lchild=insert(root->lchild,item)	;
	}
	return root;
}
void inorder(NODE* root)
{
	if(root->lchild!=NULL)
		inorder(root->lchild);
	printf("%d ",root->data);
	if(root->rchild!=NULL)
		inorder(root->rchild);
}
void preorder(NODE* root)
{
	printf("%d ",root->data);
	if(root->lchild!=NULL)
		preorder(root->lchild);
	if(root->rchild!=NULL)
		preorder(root->rchild);
}
void postorder(NODE*root)
{
	if(root->lchild!=NULL)
		postorder(root->lchild);
	if(root->rchild!=NULL)
		postorder(root->rchild);
	printf("%d ",root->data);
}











