#ifndef tree
#define tree

#include "Queue.h"
#include "Stack.h"
using namespace std;

struct Node{
    int d;
    int height;
    Node* left;
    Node* right;
    Node(int d):d(d),left(NULL),right(NULL){}
    Node(int d, int h):d(d),height(h),left(NULL),right(NULL){}
};

class BST{
    protected:
    Node* root;
    void inorder(Node* p){
            if(p == NULL)
                return;
            inorder(p->left);
            cout << p->d << ' ';
            inorder(p->right);
        }
    void preorder(Node* p){
            if(p == NULL)
                return;
            cout << p->d << ' ';
            preorder(p->left);
            
            preorder(p->right);
    }
    public:
        BST(){root = NULL;}
        virtual void insert(int d){
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

        Node* breadthfirst(int val){
            Queue<Node*> q;
            Node* p=root;
            q.enQueue(p);
            
            while(!q.empty()){
                p = q.peek();
                q.deQueue();
                
                if(p->d == val)
                    return p;
                if(p->left)
                    q.enQueue(p->left);
                if(p->right)
                    q.enQueue(p->right);
            }
        }
        Node* depthfirst(int val){
            Stack<Node*> s;
            Node* p = root;
            s.push(p);
            Node* d = s.peek();
            while(!s.empty()){
                p = s.peek();
                s.pop();
                if(p->d == val)
                    return p;
                if(p->left)
                    s.push(p->left);
                if(p->right)
                    s.push(p->right);
            }
        }
        void inorder(){
            inorder(root);
        }
        void preorder(){
            preorder(root);
        }
        

};

#endif