#include<iostream>
using namespace std;

class Node
{
	public:
		int data;
		Node* next;
};

class Circular_LL
{
	Node* head;
	Node* last;

	public:
	
	Circular_LL() 
	{
		
		head = last = new Node;
	}
	
	addToEmpty(int data) 
	{
    Node *temp =  new Node;

    temp -> data = data; 
    head = last = temp; 
    last -> next = last; 
	} 
  

	enque(int data) 
	{ 
    if (last == NULL) 
        return addToEmpty(data); 
      
    Node *temp =  new Node;
  
    temp -> data = data; 
    temp -> next = last -> next; 
    last -> next = temp; 
    last = temp; 
	} 
  
  
	void traverse() 
	{ 
    Node *p; 
    if (last == NULL) 
    { 
        cout << "List is empty." << endl; 
        return; 
    } 
    p = last -> next; 
    do
    { 
        cout << p -> data << " "; 
        p = p -> next; 
  
    } 
    while(p != last->next); 
	}
	
	int deque()
	{
		int n=head->data;
		head = head->next;
		last->next=head;
		return n;
		 
	}
	
	
	
};

int main()
{
	Circular_LL l1;
	l1.addToEmpty(4);
	l1.enque(2);
	l1.enque(3);
	l1.enque(1);
	l1.traverse();
	cout<<endl;
	l1.traverse();
	cout<<endl<<l1.deque();
	cout<<endl;
	l1.traverse();
	
	getchar();
	return 0; 
}
