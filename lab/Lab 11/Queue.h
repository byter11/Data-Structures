template<class T>
struct QNode { 
    T data; 
    QNode* next; 
    QNode(T d){ 
        data = d; 
        next = NULL; 
    } 
}; 

template<class T>
class Queue { 
    public:
    QNode<T> *front, *rear; 
    Queue(){ 
        front = rear = NULL; 
    } 

    void enQueue(T x){
        if(!front && !rear){
            front = rear = new QNode<T>(x);
            return;
        }
        rear->next = new QNode<T>(x);
        rear = rear->next;
    } 

    void deQueue(){ 
        if(!front && !rear)
            return;
        if(front == rear)
            front = rear = NULL;
        else
            front = front->next;
    }
    T peek(){
        if(front)
            return front->data;
    }
    bool empty(){
        return !front && !rear;
    }
};

