  /*Your task is to create a class DSA in DSA.h file and declare two functions ‘insertion’ and ‘searching’ in it
  in addition to the functions discussed in the rule of three. Now inherit two classes ‘Ordered Dynamic
  Safe Array’ and ‘Unordered Dynamic Safe Array’ and implement both the functions for these classes.*/

  class DSA{
  protected:
  int *arr;
  size_t size;
  int no_of_items;
  public:
    DSA(size_t size):size(size),no_of_items(0){
      arr = new int[size];

    }

    DSA(DSA& d):no_of_items(0){
      int *newarr;
      copy(arr, arr+size, newarr);
    }

    DSA& operator=(DSA& d){
    arr = new int[d.size];
    size = d.size;
    no_of_items = d.no_of_items;
    copy(d.arr, d.arr + size, arr);
    return *this;
    }

    int& operator[](size_t i){
      if(i<size){
        return arr[i];
      }
      cout << "Index out of bounds, exiting\n";
      exit(1);
    }

    virtual void insert(int val) = 0;

    virtual void search(int val) = 0;

    ~DSA(){
      delete [] arr;
    }
  };

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
    cout << i << endl;
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