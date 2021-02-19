#include<iostream>
#include<queue>
using namespace std;


class MaxHeap{
    int *arr;
    int capacity;
    int size;

    int parent(int i){
        return (i-1)/2;
    }
    
    int max(){
        return arr[0];
    }
    // bool isleaf(int i){
    //     return i > size;
    // }

    void siftup(int i){
        int p = parent(i);
        if(i && arr[p] < arr[i]){
            swap(arr[i], arr[p]);
            siftup(p);
        }
    }
    void siftdown(int i){
        // if(i > size)
        //     return;
        int l = left(i), r = right(i);
        int index = i;

        if(l <= size && arr[l] > arr[index])
            index = l;
        if(r <= size && arr[r] > arr[index])
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
    MaxHeap(int c):capacity(c),size(0){
        arr = new int[capacity];
    }

    void insert(int s){
        if(size >= capacity)   
            return;
        arr[size] = s;
        siftup(size);
        size++;
    }
    int extractMax(){
        int max = arr[0];
        arr[0] = arr[--size];
        siftdown(0);
        return max;
    }
    void printHeap() {
        for (int i = 0; i < size; i++) {
            cout<< arr[i]<<endl;
        }
        cout<<endl;
    }
};

int main(){
    // priority_queue<int> pq;
    // pq.push(4);
    // pq.push(4);
    // pq.push(3);
    // pq.push(4);
    // pq.push(5);
    // pq.push(5);
    // pq.push(5);
    // pq.push(5);
    // pq.push(5);
    //  for(int i=0; i<9; i++){
    //     cout << pq.top() << ' ';
    //     pq.pop();
    //  }
    
    MaxHeap m(15);
    m.insert(4);
    m.insert(4);
    m.insert(3);
    m.insert(4);
    m.insert(5);
    m.insert(5);
    m.insert(5);
    m.insert(5);
    m.insert(5);
    // m.printHeap();
    for(int i=0; i<9; i++)
        cout << m.extractMax() << ' ';
}