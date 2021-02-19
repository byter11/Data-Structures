#include "Tree.h"

class BST : public Tree{
    
    public:
    void insert(int d){
            Node* p = root, *prev;
            while(p){
                prev = p;
                if(d < p->d)
                    p = p->left;
                else
                    p = p->right;
            }
            if(root == NULL)
                root = new Node(d);
            else if (d < prev->d)
                prev->left = new Node(d);
            else
                prev->right = new Node(d);
        }
    Node* search(int d){
        Node* p = root;
        if(p->d == d)
            return p;
        while(p && p->d != d){
            if(d>p->d)
                p = p->right;
            else
                p = p->left;
        }
        return p;
    }
};