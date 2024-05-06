//program to find the whether given string is palindrome or not
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 50
char stack[MAX];
int top=-1;
void push(char );
char pop();

int isPalindrome(char s[]);

void push(char item)
{
	if(top==MAX-1)
		printf("stack overflow:\n");
	else
		stack[++top]=item;	
}

char pop()
{
	if(top==-1)
		printf("stack underfow:\n");
	else
		return stack[top--];
}

int isPalindrome(char s[])
{
	int i,n;
	char item;
	n=strlen(s);
	for(i=0;i<n/2;i++)
		push(s[i]);
	if(n%2==1)//if the given stringp is odd
		i=(n/2)+1;	
	else//the gven string is even
		i=n/2;	
	while(s[i]!='\0')
	{
		item=pop();
		if(item!=s[i])
			return 0;
		else
			i++;	
	}
	return 1;
}

int main()
{
	char s[MAX];
	printf("enter the string expression:\n");
	scanf("%s",s);
	if(isPalindrome(s))
		printf("given string is a palindrome\n");
	else
		printf("given string is not a palindrome\n");	
}
