#include "Tree.h"

class BT : public Tree{
    void insert(int d, Node* p){
        if(root == NULL){
            root = new Node(d);
            return;
        }
        else if(!p->left){
            p->left = new Node(d);
            return;
        }
        else if(!p->right){
            p->right = new Node(d);
            return;
        }
        else{
            if(p->left->left && p->left->right)
                insert(d, p->right);
            else
                insert(d, p->left);
        }
    }
    Node* search(int d, Node* p){
        if(p==NULL)
            return NULL;
        if(p->d == d)
            return p;
        search(d, p->left);
        search(d, p->right);
    }

    public:
    void insert(int d){
            insert(d, root);
        }
    Node* search(int d){
            return search(d, root);
        };
};