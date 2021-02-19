#include <iostream>
#include <queue>
using namespace std;

struct Node{
    int d;
    Node* left;
    Node* right;
    Node(int d):d(d),left(NULL),right(NULL){}
};

class Btree{
    Node* root;
    void inorder(Node* p){
            if(p == NULL)
                return;
            inorder(p->left);
            cout << p->d << ' ';
            inorder(p->right);
        }
    
    int countNodes(Node* p){
        if(p==NULL)
            return 1;
        return countNodes(p->left) + countNodes(p->right);
    }
    int countLeaves(Node* p){
        if(!p)
             return 0;
 
        if(!p->left && !p->right)
            return 1;
        
        return countLeaves(p->left) + countLeaves(p->right);
    }
    int countRightChildren(Node* p){
        if(!p)
            return 0;
        return !!p->right + countRightChildren(p->left) + countRightChildren(p->right);
    }
    int findHeight(Node* p){
        if(!p)
            return 0;

        return 1 + max( findHeight(p->left), findHeight(p->right) );
    }
    void delLeaves(Node* p, Node* prev){
        if(!p)
            return;
        if(!p->left && !p->right){
            if(!prev)
                root = NULL;
            else{
                cout << p->d << ' ';
                if(prev->left == p)
                    prev->left = NULL;
                else
                    prev->right = NULL;
            }
        }
        
        delLeaves(p->left, p);
        delLeaves(p->right, p);
    }
    bool isSearchTree(Node* p){
        if(!p)
            return true;

        isSearchTree(p->left);
        isSearchTree(p->right);
        return( (p->left? p->left->d < p->d : true) && (p->right? p->right->d > p->d : true) );
        
    }
    
    public:
        Btree(){root = NULL;}
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
        void print(){

            queue<Node*> q;
            Node* p=root;
            q.push(p);
            
            int row = 0;
            int cur = 0;
            int h = this->findHeight(p)+1;
            int spaces = h*h;
            while(!q.empty()){
                p = q.front();      q.pop();
                if(this->findHeight(p) < h && p->d!=-1){
                    h--;
                    spaces /= 2;
                    cout << '\n';
                    for(int i=0;i<spaces;i++)
                        cout << ' ';
                }
                else{
                for(int i=0;i<spaces*2;i++)
                    cout << ' ';
                }
                if(p->d != -1)
                    cout << p->d;
                if(h==1)
                    continue;
                if(p->left)
                    q.push(p->left);
                else
                    q.push(new Node(-1));
                if(p->right)
                    q.push(p->right);
                else q.push(new Node(-1));
            }

        }
        void inorder(){
            inorder(root);
        }
        int countNodes(){
            return countNodes(root) - 1;
        }
        int countLeaves(){
            return countLeaves(root);
        }
        int countRightChildren(){
            return countRightChildren(root);
        }
        int findHeight(){
            return findHeight(root);
        }
        void delLeaves(){
            delLeaves(root, NULL);
        }
        bool isSearchTree(){
            return isSearchTree(root);
        }
};

int main(){
    Btree b;
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
    cout << "Nodes: " << b.countNodes() << '\n';
    cout << "Leaves: " << b.countLeaves() << '\n';
    cout << "Right Children: " << b.countRightChildren() << '\n';
    cout << "Height: " << b.findHeight() << '\n';
    
   

    cout << "Nodes: " << b.countNodes() << '\n';
    cout << "\n";

    cout << "Final Tree in-order Depth-First: ";
    b.inorder();
    cout << "\nThe tree is" << (b.isSearchTree()? " " : " not ") << "a binary search tree\n";
    b.print();
    
}