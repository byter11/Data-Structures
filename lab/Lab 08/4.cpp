#include <iostream>
using namespace std;
#include "QStack.h"
int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.enQueue(40);
    s.enQueue(50);
    s.deQueue();
    s.print();
}