#include<iostream>
using namespace std;

struct Device{
    int id;
    Device* next;
    Device(int id):id(id){next = NULL;}
};

class Network{
    Device* router;
    
    public:
    Network(){
        router = new Device(0);
    }
    
    void add_device(int id){
        if(!router->next){
            
            router->next = new Device(id);
            router->next->next = router->next;
            return;
        }
        Device* first = router->next;
        while(first->next != router->next){
            
            first = first->next;
        }
        first->next = new Device(id);
        first->next->next = router->next;
    }
    void view_network(){
        Device* first = router;
        do{
            first = first->next;
            cout << first->id << ' ';
        }
        while(first->next != router->next);
        cout << '\n';
    }
};
int main(){
    Network* network = new Network();
    for(int i=0;i<6;i++)
        network->add_device(i+1);
    network->view_network();
    return 0;
}

    