#include <iostream>

using namespace std;

class Node
{
public:
	int d;
	Node* next;
	Node()
	{
		d = 0;
		next = NULL;
	}
};

void insertNode(int data, Node* head)
{
	Node* p = head;
	if(p == NULL)
	{
		p->d = data;
		head = p;
		cout<<"Node inserted"<<endl;
	}
	else
	{
		while(p->next != NULL)
		{
			p = p->next;
		}
		p->next = head;
		cout<<"Node inserted"<<endl;
	}
}

void printList(Node* head)
{
	if(head != NULL)
	{
		while(head->next != NULL)
		{
			cout<<"("<<head->d<<head->next<<")"<<"-->";
			head = head->next;
		}
	}
	else
	{
		cout<<"empty list"<<endl;
	}

	cout<<endl;
}

int main()
{
	Node* head = NULL;
	insertNode(1, head);
	insertNode(2, head);
	insertNode(3, head);
	insertNode(4, head);
	printList(head);
	
/*	insertAtPos(3, head);
	printList();
	insertAtPos(6, head);
	printList();
	
	deleteAtPos(3);
	printList();
	deleteAtPos(1);
	printList();
	deleteAtPos(5);
	printList();*/
	
	return 0;
}