#include<iostream>
using namespace std;

#define MAX 5
class ArrayCQ{
    int arr[MAX];
    int count;
    int front;
    int rear;
    public:
    ArrayCQ():count(0), front(0), rear(0){}
    void enQueue(int x){
        if( isFull() ){
            cout << "Queue Overflow!\n";
            return;
        }
        if(front == MAX)
            front = 0;
        arr[front] = x;
        front++;
        count++;
    }
    int deQueue(){
        if(isEmpty()){
            cout << "Queue Underflow!\n";
            return -1;
        }
        count--;
        int data = arr[rear];  
        rear++;
        if(rear == MAX)
        rear = 0;
        return data;
    }
    bool isEmpty(){
        return count == 0;
    }
    bool isFull(){
        return count == MAX;
    }
    
};

int main(){
    ArrayCQ q;
    for(int i=1;i<=5;i++)
        q.enQueue(i);
    cout << q.deQueue() << ' ';
    q.enQueue(6);
    for(int i=0;i<5;i++)
        cout << q.deQueue() << ' ';
    return 0;
}