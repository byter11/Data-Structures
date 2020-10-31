#include <iostream>
using namespace std;
#include "ODSA.h"
#include "UDSA.h"
int main()
{
  OrderedDSA od(5);
  od.insert(3);
  od.insert(2);
  od.insert(6);
  UnorderedDSA ud(5);
  ud.insert(4);
  ud.insert(9);
  ud.insert(3);
  cout << "Ordered: ";
  for(int i=0;i<5;i++)
    cout << od[i] << ' ';
  cout << '\n';
  cout << "Unordered: ";
  for(int i=0;i<5;i++)
    cout << ud[i] << ' ';
	return 0;
}