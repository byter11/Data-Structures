#include <iostream>
using namespace std;

int Sum_Num(int* arr, int size){
    if(size<=0)
        return 0;
    if( (*arr) %2 == 0) 
        return *arr + Sum_Num(arr+1, size-1);
    return Sum_Num(arr+1, size-1);
}

int main(){
    int arr[6] = {2, 4, 2, 3, 2, 3};
    cout << Sum_Num(arr, 6);
}