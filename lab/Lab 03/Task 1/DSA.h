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
      fill(arr, arr+size, 0);
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

    void insert(int val);

    void search(int val);

    ~DSA(){
      delete [] arr;
    }
  };

  