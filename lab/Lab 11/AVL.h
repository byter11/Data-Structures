#include <iostream>
#include "BST.h"
using namespace std;

class AVL_BST : public  BST{
        Node* insert(int x, Node* t){
        if(t == NULL)
            t = new Node(x, 0);
        else if(x < t->d){
            t->left = insert(x, t->left);
            if(balance(t) == 2){
                t = x < t->left->d ?
                        singleRightRotate(t)
                    :   doubleRightRotate(t);
                }
            }
        else if(x > t->d){
            t->right = insert(x, t->right);
            if(balance(t) == -2){
                t = x > t->right->d ?
                        singleLeftRotate(t)
                    :   doubleLeftRotate(t);
                }
            }
        t->height = height(t);
        return t;
    }

    int height(Node* t){
        if(!t)
            return 0;
        return 1 + max(height(t->left), height(t->right));
    }

    int balance(Node* t){
        return  (t->left ? t->left->height  : 0) -
                (t->right? t->right->height : 0);
    }

    Node* singleRightRotate(Node* t){
        Node* u = t->left;
        t->left = u->right;
        u->right = t;
        t->height = height(t);
        u->height = height(u);
        return u;
    }
    Node* singleLeftRotate(Node* t){
        Node* u = t->right;
        t->right = u->left;
        u->left = t;
        t->height = height(t);
        u->height = height(t);
        return u;
    }
    Node* doubleRightRotate(Node* t){
        t->left = singleLeftRotate(t->left);
        return singleRightRotate(t);
    }
    Node* doubleLeftRotate(Node* t){
        t->right = singleRightRotate(t->right);
        return singleLeftRotate(t);
    }
    public:
    void insert(int x){
        root = insert(x, root);
    }
        
        
        
};