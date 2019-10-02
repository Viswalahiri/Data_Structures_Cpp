#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

struct Node{
	int data;
	struct Node* next;
};
struct Node* head = NULL;

void insert_at_beginning(int value)
{
	struct Node* new_node;
	new_node = (struct Node*) malloc (sizeof(struct Node));
	new_node->data = value;
	if(head == NULL)
	{
		new_node->next=NULL;
		head=new_node;
	}
	else
	{
		new_node->next=head;
		head=new_node;
	}
}

void insert_at_end(int value)
{
	struct Node* new_node;
	new_node = (struct Node* )malloc(sizeof(struct Node));
	new_node->data=value;

	struct Node* temp = head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next = new_node;
	new_node->next=NULL;
}

void insert_at_position(int value,int position)
{
	if(position==0)
	{
		insert_at_beginning(value);
	}
	else
	{
	struct Node* new_node;
	new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data=value;
	int counter=0;
	struct Node* temp = head;

		for (int i=0;i<position-1;i++)
		{
			if(temp->next==NULL)
			{
				temp->next=new_node;
				new_node->next=NULL;
				counter=1;
				i=position-1;
			}
			else
			{
				temp=temp->next;
			}
		}

		if(counter==0)
		{
			new_node->next=temp->next;
			temp->next=new_node;
		}
	}
}

void display()
{
	struct Node* temp=head;
	while(temp->next!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<temp->data;
}

int main()
{
//	insert_at_beginning(5);
//	insert_at_end(7);
//	insert_at_beginning(10);
//	insert_at_beginning(15);
//	insert_at_position(44,0);
//	insert_at_position(47,2);
//	
	
	display();
}
