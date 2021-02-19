#include <iostream>
#include <fstream>
#include "BST.h"
using namespace std;

int main(){
    ifstream in;
    for(int i=0; i<5; i++){
        BST b;
        in.open("CS218-A3-testcases/A3P2/input00" + to_string(i) + ".txt");
        cout << "Test Case " << i << ": ";
        int n;
        while(in >> n)
            b.insert(n);
        
        b.PathWiseSum();
        in.close();

    }
}