#include <iostream>
using namespace std;


void reverse(int* arr, int l, int r){
    if( l >= r ) return;
    swap(arr[l], arr[r]);
    return reverse(arr, l+1, r-1);
}
int main(){
    int arr[6] = {2, 4, 2, 3, 2, 3};
    cout << "Array: ";
    for(int a: arr) 
        cout << a << ' ';
    reverse(arr, 0, 5);
    cout << "\n\nReversed: ";
    for(int a: arr) 
        cout << a << ' ';
}
