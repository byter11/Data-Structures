#include<iostream>
#include "BST.h"
#include "AVL.h"
using namespace std;
int main(){
    BST b;
    b.insert(4);
    b.insert(3);
    b.insert(6);
    b.insert(2);
    b.insert(7);
    b.insert(1);
    Node* p = NULL;
    p = b.breadthfirst(7);
    if(p)
        cout << "Found using breadth first " << p->d;

    p = NULL;
    p = b.depthfirst(6);
    if(p)
        cout << "\nFound using depth first " << p->d << '\n';

    else
        cout << "Not found";
    cout << "\nAVL tree preorder:\n";
    AVL_BST a;
    a.insert(43);
    a.insert(44);
    a.insert(42);
    a.insert(41);
    a.insert(40);
    a.insert(39);
    a.preorder();
    
}