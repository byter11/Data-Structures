#include <iostream>
using namespace std;
#include "DSA.h"

int main()
{
  OrderedDSA d(5);
  d.insert(3);
  d.insert(2);
  d.insert(6);
  for(int i=0;i<5;i++)
    cout << d[i] << ' ';
	return 0;
}