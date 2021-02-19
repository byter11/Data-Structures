#include<iostream>

using namespace std;

class Node
{
	public:
	int data;
	Node* next;
	Node* previous;
};

class DLL
{
	public:
	Node* head;
	
	DDL()
	{
		head = NULL;
	}
	
	void traverse1()
	{
	Node* temp = head;
	while(temp != NULL)
    {
    cout<<temp->data<<endl;
    temp = temp->next;
	}
	}
	
	void traverse2()
	{
	Node* temp = head;
	while(temp->next != NULL)
    {
    //cout<<temp->data<<endl;
    temp = temp->next;
	}
	
	while(temp!=NULL)
	{
	cout<<temp->data<<endl;
    temp = temp->previous;
	}
	
	}
	
	void insert_at_first(int data)
	{
	//Step 1
	Node* new_node = new Node();
	new_node->data = data;
	//Step2
	new_node->next = head;
	new_node->previous = NULL;
	//Step3
	if(head!=NULL)
	{
	head->previous = new_node;
	}
	head = new_node;
	}
	
	swap()
	{
	if(head==NULL) return 1;
	
	Node* temp = head->next;
	
	head->next = head->next->next;
	head->next->previous = head;
	
	temp->next = head->next->next;
	head->next->next = temp;
	temp->previous = head->next;
	
	return 1;	
	}
	
	insert_at_last(int data)
	{
		Node* new_node = new Node();
		new_node->data = data;
		new_node->next = NULL;
		
		Node* temp = head;
		
		while(temp->next != NULL)
    	{
    	//cout<<temp->data<<endl;
    	temp = temp->next;
		}
		temp->next = new_node;
		new_node->previous = temp;
	}
};

int main()
{
	DLL d;
	d.insert_at_first(1);
	d.insert_at_first(2);
	d.insert_at_first(3);
	
	d.traverse1();
	
	cout<<endl;
	
	d.swap();
	
	d.traverse1();
	
	cout<<endl;
	
	d.traverse2();
	
	cout<<endl;
	
	d.insert_at_last(4);
	d.insert_at_last(5);
	
	d.traverse1();
	
	getchar();
	
	system("Pause");
	
	return 1;
}
