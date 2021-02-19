#include<iostream>
#include "AdjMatrixGraph.h"
using namespace std;

int main(){
    Graph g;
    g.addVertex();
    g.addVertex();
    g.addVertex();
    g.addVertex();
    g.addEdge(1,2);
    g.addEdge(1,3);
    cout << "Graph: ";
    g.print();
    cout << "BFS: ";
    g.BFS(1);
    return 0;
}