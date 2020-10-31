#include<bits/stdc++.h>
using namespace std;
#include "SinglyList.h"
#include "DoublyList.h"

int main(){
    SinglyList s1;
    srand(time(NULL));
    int c;
    for(int i=0; i<10; i++){
        s1.push( rand()%10 );
    }
    SinglyList s2(s1), s3(s1);
    // s1.print();
    // s1.BubbleSort();
    // s1.print();
    DoublyList d1;
    for(int i=0; i<10; i++)
        d1.push(rand()%10);
    d1.print();
    d1.SelectionSort();
    d1.print();
}