#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector< vector<int> > jarr;
    while(1){
        int c;
        cout << "1. Add array\n2. Print\n";
        cin >> c;
        switch(c){
            case 1:{
                int l;
                cout << "Length: ";
                cin >> l;
                vector<int> arr(l);
                int i=0;
                cout << "Array: ";
                while(i < l){
                    cin >> arr[i];
                    i++;
                }
                jarr.push_back(arr);
                break;
            }
            case 2:{
                for(auto a:jarr){
                    cout << '\n';
                    for(int n:a){
                        cout << n << ' ';
                    }
                    
                }
                cout << "\n\n";
                break;
            }
        }
    }
}