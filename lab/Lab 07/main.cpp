#include<bits/stdc++.h>
using namespace std;
#include "SinglyList.h"
#include "DoublyList.h"

int main(){
    srand(time(NULL));

    SinglyList s1;
    DoublyList d1, d2;
    for(int i=0; i<10; i++){
        s1.push(rand()%10);
        d1.push(rand()%10);
        d2.push(rand()%10);
    }
    
    cout << "Singly List: ";
    s1.print();
    cout << "Bubble Sorted: ";
    s1.BubbleSort();
    s1.print();

    cout << "\nDoubly List: ";
    d1.print();
    cout << "Selection Sorted: ";
    d1.SelectionSort();
    d1.print();

    cout << "\nDoubly List: ";
    d2.print();
    cout << "Insertion Sorted: ";
    d2.InsertionSort();
    d2.print();
    
}