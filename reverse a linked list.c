#include<stdio.h>
#include<stdlib.h>

int val;
struct node *start=NULL,*newnode,*temp,*next,*last,*post,*post1;

struct node
{
	struct node *next;
	int data;
};

int display()
{
	temp = start;
	while(temp!=NULL)
	{
		printf("%d \t",temp->data);
		temp=temp->next;
	}
};

int main()
{
	printf("Enter the value for node of list 1: ");
	 scanf("%d",&val);
	
	do
	{
		newnode = (struct node *)malloc(sizeof(struct node));
		newnode->data=val;
		
		
		if(start == NULL)
		{
			start = newnode;
			newnode->next=NULL;
		}
		
		else 
		{
			temp = start;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=newnode;
			newnode->next=NULL;
		}
		printf("Enter the value for node of list 1 or press -1 to exit: ");
		scanf("%d",&val);
	}
	while(val!=-1);
	printf("Original list: ");
	display();
	printf("\n");
	
	printf("Reversed list: ");
	
	last = start;
	while(last->next!=NULL)
	{
		last=last->next;
	}
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=start->data;
	last->next=newnode;
	newnode->next=NULL;
	
	
	while(start->next!=last)
	{
		
		start=start->next;
		post=start->next;
		newnode=(struct node *)malloc(sizeof(struct node));
		newnode->data=start->data;
		newnode->next=last->next;
		last->next=newnode;
		post1=newnode;
	}
	
	temp = last;
	while(temp!=NULL)
	{
		printf("%d \t",temp->data);
		temp=temp->next;
	}
	
}
