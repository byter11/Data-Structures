#include<iostream>
using namespace std;
#include "Car.h"

int main(){
    Car c1(800,200,400);
    Car c2 = c1;
    Car c3;
    c3 = c1;
    return 0;
}
