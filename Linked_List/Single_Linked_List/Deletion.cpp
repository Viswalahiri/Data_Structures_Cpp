#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

struct Node{
	int data;
	struct Node* next;
};
struct Node* head = NULL;

void delete_first_element()
{
	if (head == NULL)
	{
		cout<<"There is nothing to delete.";
	}
	else
	{
		struct Node* temp = head;
		head=temp->next;
		free(temp);
	}
}

void delete_last_element()
{
	if(head == NULL)
	{
		cout<<"There is nothing to delete.";
	}
	else
	{
		struct Node *temp1=head, *temp2;
		while(temp1->next!=NULL)
		{
			temp2=temp1;
			temp1=temp1->next;
		}
		temp2->next=NULL;
		free(temp1);
	}
}

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

void delete_at_position(int position)
{
	if(head==NULL)
	{
		cout<<"The list is empty."<<endl;
	}
	else
	{
		int counter=0;
		if(position==0)
		{
			delete_first_element();	
		}
		else
		{
			
		struct Node *temp1=head, *temp2;
			for (int i=0 ; i<position-1 ; i++)
			{
				temp2=temp1;
				temp1=temp1->next;
				if(temp1->next == NULL)
				{
					temp2->next=NULL;
					free(temp1);
					counter=1;
					i=position-1;
				}	
			}
		if(counter==0)
		{
			temp2->next=temp1->next;
			free(temp1);
		}
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
	insert_at_beginning(5);
	insert_at_position(44,1);
	insert_at_end(7);
	insert_at_beginning(10);
	insert_at_beginning(15);
	insert_at_position(47,2);
	display();
	cout<<endl;
	delete_at_position(6);
	display();
	cout<<endl;
	delete_last_element();
	display();
	cout<<endl;
}
