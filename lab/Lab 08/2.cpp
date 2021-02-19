#include <iostream>
using namespace std;
#include "Queue.h"

int main(){
    Queue q;
    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(-4);
    q.enQueue(5);
    q.enQueue(-6);

    cout << "Queue Before: ";
    q.print();
    
    
    q.remove_negatives();
    cout << "\nQueue After: ";
    q.print();

    return 0;
}