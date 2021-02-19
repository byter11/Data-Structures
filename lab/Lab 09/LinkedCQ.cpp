#include<iostream>
using namespace std;

#define MAX 5
struct Node{
    int data;
    Node* next;
    Node(int d):data(d){
        next = NULL;
    }
};

class LinkedCQ{
    Node* front;
    Node* rear;
    int count = 0;
    public:
    LinkedCQ(){
        rear = front = new Node(0);
        for(int i=0;i<MAX-1;i++){
            front->next = new Node(0);
            front = front->next;
        }
        front->next = rear;
        front = rear;
    }
    void enQueue(int x){
        if(count == MAX){
            cout << "Queue Overflow!\n";
            return;
        }
        front->data = x;
        front = front->next;
        count++;
    }
    int deQueue(){
        if(count == 0){
            cout << "Queue Underflow!\n";
            return -1;
        }
        int data = rear->data;
        rear = rear->next;
        count--;
        return data;
    }

};
int main(){
    LinkedCQ q;
    for(int i=1;i<=5;i++)
        q.enQueue(i);
    cout << q.deQueue() << ' ';
    q.enQueue(6);
    for(int i=0;i<5;i++)
        cout << q.deQueue() << ' ';
    
}