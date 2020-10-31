#include <iostream>
using namespace std;

#include "List.cpp"

List BuildOneTwoThree(){
  List list;
  for(int i=0; i<3;i++){
    list.addNode(i+1);
  }
  return list;
}
void CountTest(){
  List myList = BuildOneTwoThree();
  int count = myList.count(3);
  cout << count;
}

int main() {
  List myList = BuildOneTwoThree();
  List newlist;
  for(int i=0;i<5;i++)
    newlist.addNode(i);
    
  CountTest();
  cout << "\n";
  cout << "The lists are"<<( myList.compare(newlist)? "" : " not" ) << " equal.\n";
  newlist.display();
  newlist.delNode(3);
  newlist.display();
  newlist.insertNode(2,6);
  newlist.display();
  cout << "2" << (newlist.searchNode(2)? "": " not") << " found in newlist\n";
  newlist.reverseList();
  newlist.display();
  cout << "\nThe list is"<<( newlist.isCircular()? "" : " not" ) << " circular.\n";
  newlist.makeCircular();
  cout << "\nThe list is"<<( newlist.isCircular()? "" : " not" ) << " circular.\n";
  return 0;
}

