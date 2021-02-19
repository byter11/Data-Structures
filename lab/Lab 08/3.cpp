#include <iostream>
using namespace std;
#include "Queue.h"

int main(){
    Queue q;
    q.enQueue(10);
    q.enQueue(20);
    q.enQueue(30);
    q.enQueue(40);
    q.enQueue(50);
    cout << "Before reverse: ";
    q.print();
    q.reverse();
    cout << "After reverse: ";
    q.print();
}