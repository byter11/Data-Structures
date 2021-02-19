#include <iostream>
using namespace std;
#include "Queue.h"
    
int main(){ 
    Queue q; 

    q.enQueue(10);
    q.enQueue(20); 
    
    q.deQueue(); 
    q.deQueue(); 

    
    q.enQueue(30); 
    q.enQueue(40);
    q.enQueue(50);
    
    q.deQueue(); 

    cout << "Queue Front : " << (q.front)->data << endl;    
    cout << "Queue Rear : " << (q.rear)->data;
    
}