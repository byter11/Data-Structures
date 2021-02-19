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
	Node* last;

	public:
	
	Circular_LL() 
	{
		Node* last = new Node;
	}
	
	addToEmpty(int data) 
	{   
    // Creating a node dynamically. 
    Node *temp =  new Node;
  
    // Assigning the data. 
    temp -> data = data; 
    last = temp; 
  
    // Creating the link. 
    last -> next = last; 
	} 
  
	addBegin(int data) 
	{ 
    if (last == NULL) 
        return addToEmpty(data); 
  
	Node *temp =  new Node;
  
    temp -> data = data; 
    temp -> next = last -> next; 
    last -> next = temp; 
	} 
  
	addEnd(int data) 
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
  
    // If list is empty, return. 
    if (last == NULL) 
    { 
        cout << "List is empty." << endl; 
        return; 
    } 
  
    // Pointing to first Node of the list. 
    p = last -> next; 
  
    // Traversing the list. 
    do
    { 
        cout << p -> data << " "; 
        p = p -> next; 
  
    } 
    while(p != last->next); 
	}
	
	void removet()
	{
		Node* temp1 = new Node();
		temp1 = last;
		
		while(temp1->next != last)
		{
			
			temp1 = temp1->next;
		}
		
		//cout<<endl<<temp1->data;
		temp1->next = last->next;
		last = temp1;	 
	}
	
	
	
};

int main()
{
	Circular_LL l1;
	l1.addToEmpty(4);
	l1.addEnd(2);
	l1.addBegin(3);
	l1.addBegin(1);
	l1.traverse();
	cout<<endl;
	l1.traverse();
	l1.removet();
	cout<<endl;
	l1.traverse();
//	l1.removea();
//	l1.traverse();
	
	getchar();
	return 0; 
}
