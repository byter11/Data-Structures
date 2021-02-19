#include <iostream>
using namespace std;
#include "BST.h"
#include "BT.h"

int main(){
    cout << "BT:\n";
    BT a;
    a.insert(15);
    a.insert(12);
    a.insert(16);
    a.insert(20);
    a.insert(21);
    a.insert(17);
    a.insert(5);
    a.insert(1);
    a.insert(3);
    a.insert(18);

    cout << "Preorder: ";
    a.i_preorder();

    cout << "\nInorder: ";
    a.i_inorder();
    
    cout << "\nPostorder: ";
    a.i_postorder();


    cout << "\n\nBST:\n";
    BST b;
    Node* p;
    b.insert(15);
    b.insert(12);
    b.insert(16);
    b.insert(20);
    b.insert(21);
    b.insert(17);
    b.insert(5);
    b.insert(1);
    b.insert(3);
    b.insert(18);

    p = b.search(21);
    if(p)
        cout << "Found " << p->d;

    cout << "\nPreorder: ";
    b.i_preorder();

    cout << "\nInorder: ";
    b.i_inorder();
    
    cout << "\nPostorder: ";
    b.i_postorder();
    
}