using namespace std;

struct Node{
    int d;
    Node* left;
    Node* right;
    Node(int d):d(d),left(NULL),right(NULL){}
};

class BST{
    Node* root;
    
    int height(Node* p){
        if(!p)
            return 0;
        return 1 + max(height(p->left), height(p->right));
    }
    void preorder(Node* p){
            if(p == NULL)
                return;
            cout << p->d << ' ';
            preorder(p->left);
            
            preorder(p->right);
    }

    void LevelWiseSum(Node* p, int level, int* arr){
        if(!p)
            return;
        
        arr[level] += p->d;

        LevelWiseSum(p->left, level+1, arr);
        LevelWiseSum(p->right, level+1, arr);
    }

    void PathWiseSum(Node* p, int sum){
        if(!p)
            return;
        if(!p->left && !p->right){
            cout << sum+p->d << '-';
            return;
        }

        PathWiseSum(p->left, sum+p->d);
        PathWiseSum(p->right, sum+p->d);       
    }
 
    public:
    BST(){root = NULL;}
    void preorder(){
            preorder(root);
        }

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
    
    void LevelWiseSum(){
        int arr[height(root)] = {0};

        LevelWiseSum(root, 0, arr);

        for(int i: arr)
            cout << i << '-';

        cout << "\b \n";
    }

    void PathWiseSum(){
        PathWiseSum(root, 0);
        cout << "\b \n";
    }
};