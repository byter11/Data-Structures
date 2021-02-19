#ifndef tree
#define tree

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct Node{
    int d;
    Node* left;
    Node* right;
    Node(int d):d(d),left(NULL),right(NULL){}
};

class Tree{
    protected:
    Node* root;
    void preorder(Node* p){
            if(p == NULL)
                return;
            cout << p->d << ' ';
            preorder(p->left);
            
            preorder(p->right);
    }
    void inorder(Node* p){
            if(p == NULL)
                return;
            inorder(p->left);
            cout << p->d << ' ';
            inorder(p->right);
        }
    void postorder(Node* p){
            if(p == NULL)
                return;
            postorder(p->left);
            postorder(p->right);
            cout << p->d << ' ';
        }
    
    public:
        Tree(){root = NULL;}
        virtual void insert(int d) = 0;
        virtual Node* search(int d) = 0;

        void i_preorder(){
            queue<Node*> q;
            Node* p=root;
            q.push(p);
            while(!q.empty()){
                p = q.front();
                q.pop();
                cout << p->d << ' ';
                if(p->left)
                    q.push(p->left);
                if(p->right)
                    q.push(p->right);
            }
        }

        void i_inorder(){
            stack<Node*> s;
            Node* p = root;
            while(!s.empty() || p){
                if(p){
                    s.push(p);
                    p = p->left;
                }
                else{
                    p = s.top();
                    s.pop();
                    cout << p->d << ' ';
                    p = p->right;
                }
                
            }
        }
        void i_postorder(){
            stack<Node*> s;
            Node* p=root, *prev;
            
            while(!s.empty() || p){
                if(p){
                    s.push(p);
                    p = p->left;
                }
                else{
                    Node* t = s.top();
                    if(t->right && prev != t->right)
                        p = t->right;
                    else{
                        cout << t->d << ' ';
                        prev = s.top();
                        s.pop();
                    }
                }

            }
        }
        void inorder(){
            inorder(root);
        }
        void preorder(){
            preorder(root);
        }
        void postorder(){
            postorder(root);
        }
};

#endif