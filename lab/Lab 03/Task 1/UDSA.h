#ifndef _DSA
    #define _DSA
    #include "DSA.h"
#endif

class UnorderedDSA: public DSA{
  public:
  UnorderedDSA(size_t size):DSA(size){}
  void insert(int val){
    if(no_of_items >= size){
      cout << "Array full";
      return;                                  
    }
    arr[no_of_items++] = val;
  }
  void search(int val){
    for(int i=0; i<size; i++){
      if(arr[i] == val){
        cout << "Found\n";
        return;
      }
    }
  cout << "Not found\n";
  }

};
