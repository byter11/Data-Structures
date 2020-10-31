#ifndef _DSA
    #define _DSA
    #include "DSA.h"
#endif
class OrderedDSA: public DSA{
  public:
  OrderedDSA(size_t size):DSA(size){}

  void insert(int val){
    if(no_of_items >= size){
      cout << "Array full";
      return;
    }

    int i=0;
    while(val < arr[i])
      i++;
    int last = arr[i];
    for(int j=i; j<=size; j++){
      int newlast = arr[j+1];
      arr[j+1] = last;
      last = newlast;
    }
    arr[i] = val;
    no_of_items++;
  }

  void search(int val){
    int l=0, r=size;
    while (l <= r) { 
          int m = l + (r - l) / 2; 
          if (arr[m] == val){
            cout << "Found\n";
            return; 
          }
              
          if (arr[m] < val) 
              l = m + 1; 
          else
              r = m - 1; 
        }  
  cout << "Not Found\n";
  }
};
