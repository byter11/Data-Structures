#include<iostream>
#include "AdjListGraph.h"
int main(){
    Graph p;
    p.addVertex('a');
    p.addVertex('b');
    p.addVertex('c');
    p.addVertex('d');
    p.addVertex('e');

    p.addEdge('a', 'e');
    p.addEdge('a', 'c');
    p.addEdge('b', 'c');
    p.addEdge('b', 'd');
    
    cout << "Graph:\n";
    p.prints();
    cout << "BFS: ";
    p.BFS();
    cout << "DFS: ";
    p.DFS();

    return 0;
}