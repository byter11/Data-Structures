#include <iostream>
#include <vector>
#include<queue>
#include<stack>
using namespace std;
class Graph{
    vector<vector<bool>> adjMatrix;
    
    public:
        void addVertex(){
            adjMatrix.emplace_back();
            for(auto& v: adjMatrix){
                adjMatrix.back().push_back(false);
                v.push_back(false);
            }
        }
        void addEdge(int i, int j){
            adjMatrix[i][j] = true;
            adjMatrix[j][i] = true;
        }
        void BFS(int src){
            int vertices = adjMatrix.size();
            bool visited[vertices] = {false};
            queue<int> q;
            q.push(src);
            visited[src] = true;

            while(!q.empty()){
                int e = q.front();
                char z = e+96;
                cout << z << ' ';
                q.pop();
                for(int i=0; i<vertices; i++){
                    if(adjMatrix[e][i]  && !visited[i]){
                        q.push(i);
                    }
                }
            }
        }
        void print(){
            for(auto& v: adjMatrix){
                for(bool b: v){
                    cout << b << ' ';
                }
                cout << '\n';
            }
            cout << '\n';
        }
};
