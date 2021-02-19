
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;
struct AdjNode{
    char vertex;
    AdjNode* next;
    AdjNode(char v):vertex(v), next(NULL){}
};


struct AdjList{
    AdjNode* head;
    AdjList* next;

    AdjList():head(NULL),next(NULL){}
    AdjList(char vertex){
        head = new AdjNode(vertex);
        next = NULL;
    }
    void insert(char v){
        if(!head)
            head = new AdjNode(v);
        else{
            AdjNode* t = head;
            while(t->next)
                t = t->next;
            t->next = new AdjNode(v);
        }
    }
};

class Graph{
    AdjList* head;
    int vertices;

    AdjList* findlist(char v){
        AdjList* t = head;
        while(t){
            if(t->head->vertex == v)    
                return t;
            t = t->next;
        }
        return nullptr;
    }
    public:
        Graph(){
            head = NULL;
            vertices = 0;
        }
    void addVertex(char v){
        if(!head)
            head = new AdjList(v);
        else{
            AdjList* t = head;
            while(t->next)
                t = t->next;
            t->next = new AdjList(v);
        }
        vertices++;
    }
    void addEdge(char v1, char v2){
        AdjList* t=head, *v1node, *v2node;
        while(t){
            if(t->head->vertex == v1)   v1node = t;
            if(t->head->vertex == v2)   v2node = t;
            t = t->next;
        }
        v1node->insert(v2);
        v2node->insert(v1);
    }
    void prints(){
        AdjList* list_t = head;
    //    cout << head->next->head->vertex;
        while(list_t){
            AdjNode* node_t = list_t->head;
            while(node_t){
                cout << node_t->vertex << "->";
                node_t = node_t->next;
            }
            cout<< "NULL";
            cout << '\n';
            list_t = list_t->next;
        }
    }
    void BFS(){
        vector<char> visited;
        queue<AdjList*> q;
        q.push(head);
        visited.push_back(head->head->vertex);
        
        while(!q.empty()){
            AdjNode* t = q.front()->head;
            cout << t->vertex << ' ';
            q.pop();
            while(t){
                if(find(visited.begin(), visited.end(), t->vertex) == visited.end()){
                    q.push(findlist(t->vertex));
                    visited.push_back(t->vertex);
                }
                t = t->next;
            }
        }
        cout << endl;
    }

    void DFS(){
        vector<char> visited;
        stack<AdjList*> s;
        s.push(head);
        visited.push_back(head->head->vertex);
        
        while(!s.empty()){
            AdjNode* t = s.top()->head;
            cout << t->vertex << ' ';
            s.pop();
            while(t){
                if(find(visited.begin(), visited.end(), t->vertex) == visited.end()){
                    s.push(findlist(t->vertex));
                    visited.push_back(t->vertex);
                }
                t = t->next;
            }
        }
        cout << endl;
    }
};

