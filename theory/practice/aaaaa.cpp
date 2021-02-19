#include <iostream>
#include <algorithm>
using namespace std;
void Indirectsort(int data[], int index[], const int n) {
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (data[index[j]] > data[index[j+1]]){
                swap(index[j], index[j+1]);
            }
        }
    }
}

int main(){
    int data[5] = {13,29,91,34,56};
    int index[5] = {0,1,2,3,4};
    Indirectsort(data, index, 5);
    for(int& i: index)
        cout << i << ' ';
}