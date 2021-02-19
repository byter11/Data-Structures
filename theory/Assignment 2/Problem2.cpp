#include<iostream>
#include<fstream>
using namespace std;

struct Process {
    int id;
    int quota;
    int cpureq;
    Process* next;
    Process(int id, int quota, int cpureq):id(id), quota(quota), cpureq(cpureq){
        next = NULL;
    }
};

class ProcessQueue {
    Process* front;
    Process* rear;
    public:
    ProcessQueue(){
        front = rear = NULL;
    }
    void enQueue(Process* p){
        p->next = NULL;
        if(!front && !rear)
            front = rear = p;
        else{
            rear->next = p;
            rear = rear->next;
        }
    }
    Process* deQueue(){
        if(front == NULL && rear == NULL)
            return NULL;
        else{
            Process* t = front;
            if(front == rear)
                front = rear = front->next;
            else
                front = front->next;
            t->next = NULL;
            return t;
        }   
    }

    void startProcessing(){
        Process* temp;
        //Run until all processes completed (queue empty)
        while(front){
                front->cpureq -= front->quota;
                if(front->cpureq <= 0){
                    cout << front->id << ' ';
                    delete this->deQueue();                    //Dequeue if completed
                }
                else
                    this->enQueue(this->deQueue());     //else send to end of queue
            }
        rear = NULL;
        cout << '\n';
    }
};

int main(){
    int num;
    int *processes = new int[num], *quotas = new int[num], *cpureqs = new int[num];
    for(int i=0; i<=5; i++){

        fstream in = fstream("./A2UpdatedTestCases/A2P2/input00"+to_string(i)+".txt", ios::in);
        in >> num;

        //Initialize lists
        for(int i=0; i<num; i++)
            in >> processes[i];
        for(int i=0; i<num; i++)
            in >> quotas[i];
        for(int i=0; i<num; i++)
            in >> cpureqs[i];

        ProcessQueue q;   
        for(int i=0; i<num; i++){
            q.enQueue( new Process( processes[i], quotas[i], cpureqs[i] )  );
        }
        //q.print();
        cout << "Test Case " << i << ": ";
        q.startProcessing();
        in.close();
    }   
}