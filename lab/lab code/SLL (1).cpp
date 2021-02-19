/* Single Linked List code by BJ */

#include <iostream>

using namespace std;

class node
{
	public:
    int data;
    node *next;
};

class linked_list
{
	private:
    node *head;
	public:
    linked_list()
    {
        head = NULL;
    }
    
    void add_node_at_front(int n)
    {
        node *tmp = new node;
        tmp->data = n;

      
        tmp->next = head;
        head = tmp;
        
    }
    
    void add_node_at_last(int n)
    {
    	node *tmp = new node;
        tmp->data = n;
        tmp->next = NULL;
        
        node *tmp2 = head;

        if(tmp2 == NULL)
        {
            head = tmp;
        }
        else
        {
        	while(tmp2->next)
        	{
        		tmp2=tmp2->next;
			}
			tmp2->next = tmp;
        }
	}
    
    void delete_node_at_front()
	{
    if(head==NULL)
		{
        cout<<"List is empty!"<<endl;
        return;
    	}
    cout<<head->data<<" is removed."<<endl;
    head=head->next;
	}
	
	void delete_node_at_end()
	{
		if(head==NULL)
		{
        cout<<"List is empty!"<<endl;
        return;
    	}
    	
    	if (head->next == NULL) 
		{ 
        delete head; 
        return; 
    	} 
    	
        node *tmp = head;
        while(tmp->next->next)
        {
        	tmp=tmp->next;
		}
			tmp->next = NULL;
    }
		
    void traverse()
    {
    	node *tmp=head;
    	
    	while(tmp!=NULL)
    	{
    		cout<<tmp->data;
    		tmp = tmp->next;
		}
	}
};

int main()
{
    linked_list a;
    a.add_node_at_front(1);
    a.add_node_at_front(2);
    a.traverse();
    cout<<endl;
    a.add_node_at_front(3);
    a.add_node_at_front(4);
    a.add_node_at_front(5);
    a.add_node_at_front(6);
    a.traverse();
    cout<<endl;
    a.delete_node_at_front();
    a.traverse();
    a.add_node_at_last(7);
    a.add_node_at_last(8);
    cout<<endl;
    a.traverse();
    cout<<endl;
    a.delete_node_at_end();
    a.traverse();
    cout<<endl;
    a.delete_node_at_end();
    a.traverse();
    
    getchar();
    return 0;
}
