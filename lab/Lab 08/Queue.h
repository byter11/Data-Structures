struct QNode { 
    int data; 
    QNode* next; 
    QNode(int d){ 
        data = d; 
        next = NULL; 
    } 
}; 

class Queue { 
    public:
    QNode *front, *rear; 
    Queue(){ 
        front = rear = NULL; 
    } 

    void enQueue(int x){
        if(!front && !rear){
            front = rear = new QNode(x);
            return;
        }
        rear->next = new QNode(x);
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
    void remove_negatives(){
        while(front && front->data < 0)
            this->deQueue();
        QNode* oldrear = rear;
        int data;
        while(front != oldrear){
            data = front->data;
            this->deQueue();
            if(data >= 0)
                this->enQueue(data);
        }
        if(front->data < 0)
            this->deQueue();
        else{
            data = front->data;
            this->deQueue();
            this->enQueue(data);
        }
    }
    void reverse(){
        rear = front;
        QNode* p = front->next;
        QNode* n = front->next;
        front->next = NULL;
        while(n){
            p = p->next;
            n->next = front;
            front = n;
            n = p;
        }
    }
    void print(){
        QNode* temp = front;
        while(temp){
            cout << temp->data << ' ';
            temp = temp->next;
        }
        cout << '\n';
    }
};

