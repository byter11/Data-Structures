#include <iostream>
#include "MinHeap.h"
using namespace std;

int main(){
    MinHeap h(11);
    for(int i=11;i>0;i--)
        h.insert(i);
    h.print();
    cout << '\n' << h.left(11) << ' ' << h.right(11);
    return 0;
}