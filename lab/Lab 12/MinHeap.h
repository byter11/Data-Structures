using namespace std;
class MinHeap{
    int *arr;
    int capacity;
    int size;

    int parent(int i){
        return i%2 ? (i/2) : (i/2)-1;
    }
    
    int max(){
        return arr[0];
    }
    bool isleaf(int i){
        return (2*i)+1 >= size;
    }

    void siftup(int i){
        if(i==0){
            
            return;
        }
        int p = parent(i);
        if(arr[p] > arr[i]){
            swap(arr[i], arr[p]);
            siftup(p);
        }
    }
    void siftdown(int i){
        if(isleaf(i))
            return;
        int l = left(i), r = right(i);
        int index = i;

        if(arr[l] < arr[i])
            index = l;
        if(!isleaf(r) && arr[r]<arr[index]);
            index = r;
        
        if(index != i){
            swap(arr[i], arr[index]);
            siftdown(index);
        }
        
    }
    public:
    int left(int p){
        return (2*p)+1;
    }
    int right(int p){
        return (2*p)+2;
    }
    MinHeap(int c):capacity(c),size(0){
        arr = new int[capacity];
    }

    void insert(int k){
        arr[size] = k;
        siftup(size);
        size++;
    }
    int extractMin(){
        int min = arr[0];
        arr[0] = arr[--size];
        siftdown(0);
        return min;
    }
    void print(){
        for(int i=0; i<size; i++)
            cout << arr[i] << ' ';
    }


};