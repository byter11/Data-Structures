#include<iostream>
using namespace std;
#include "Quadratic.h"

int main(){
    float a,b,c;
    cout << "Enter equation coefficients in form \"a b c\": ";
    cin >> a >> b >> c;
    quadratic q(a,b,c);
    float* roots = q.solve();
    cout << "Roots: " << roots[0] << "\t" <<roots[1];
    return 0;
}   