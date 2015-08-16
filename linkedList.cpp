#include <iostream>
#include <conio.h>

using namespace std;

struct node
{
	int data;
	node* next;
};

node* newNode(int);
void printList(node*);
void push(int,node**);

int main()
{
	node* head = newNode(0);
	head->next = newNode(1);
	head->next->next = newNode(2);
	node** addr_head = &head;
	push(3,addr_head);
	printList(head);
	
	_getch();
	return 0;
}

node* newNode(int data)
{
	node* temp = new node;
	temp->data = data;
	temp->next = NULL;
	return temp;	
}

void printList(node* header)
{
	node* temp = header;
	//head->data = 7;
	while(temp!=NULL)
	{
		cout<<temp->data<<",";
		temp = temp->next;
	}
	cout<<endl;
}

void push(int data,node** header)
{
	node* temp = newNode(data);
	temp->next = *header;
	*header = temp;
}
