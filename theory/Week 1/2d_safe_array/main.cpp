#include<iostream>
using namespace std;
#include "s_array.h"
int main(){
    two_array arr(5,5);
    arr[3][3] = 3;
    cout << arr[3][3];
}