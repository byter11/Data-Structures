template<class T>
struct SNode{
    T data; 
    SNode* next; 
    SNode(T d){ 
        data = d; 
        next = NULL; 
    }
};

template<class T>
class Stack{
    public:
    SNode<T>* top;
    Stack(){ top = NULL; }

    void push(T x){
        if(!top){
            top = new SNode<T>(x);
            return;
        }
        SNode<T>* newtop = new SNode<T>(x);
        newtop->next = top;
        top = newtop;
    }
    void pop(){
        if(top)
            top = top->next;
    }
    T peek(){
        return top->data;
    }
    bool empty(){
        return top == NULL;
    }
};