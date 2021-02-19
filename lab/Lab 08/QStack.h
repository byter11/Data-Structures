struct SNode{
    int data; 
    SNode* next; 
    SNode(int d){ 
        data = d; 
        next = NULL; 
    }
};

class Stack{
    public:
    SNode* top;
    Stack(){ top = NULL; }

    void push(int x){
        if(!top){
            top = new SNode(x);
            return;
        }
        SNode* newtop = new SNode(x);
        newtop->next = top;
        top = newtop;
    }
    int pop(){
        if(!top)
            return -1;
        int data = top->data;
        top = top->next;
        return data;
    }
    void enQueue(int x){
        Stack temp;
        while(top)
            temp.push( this->pop() );

        this->push(x);
        while(temp.top)
            this->push( temp.pop() );
    }
    int deQueue(){
        if(!top){
            cout << "Error: Stack Empty\n";
            return -1;
        }
        return this->pop();
    }
    void print(){
        SNode* temp = top;
        while(temp){
            cout << temp->data << ' ';
            temp = temp->next;
        }
        cout << '\n';
    }
};