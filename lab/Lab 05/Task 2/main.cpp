#include <iostream>
using namespace std;

struct Node{
  int data;
  struct Node* next;
};
void addNode(Node* tmp, int val){
    while(tmp->next != NULL){
        tmp = tmp->next;
    }
    Node* newnode = new Node();
    newnode->data = val;
    tmp->next = newnode;
}
void display(Node* tmp){
    while(tmp->next != NULL){
        tmp = tmp->next;
        cout << tmp->data << ' ';
        
      }
    cout << '\n';
}
Node* get_average_list(Node* mylist){
    Node* avglist = new Node();
    while(mylist->next != NULL){
        int avg = 0;
        Node* tmp = mylist;
        for(int i=0; i<4; i++){
            if(tmp->next == NULL){
                return avglist;
            }
            tmp = tmp->next;
            //cout << tmp->data << ' ';
            avg += tmp->data;
        }
        //cout << '\n';
        mylist = mylist->next;
        avg = avg/4;
        addNode(avglist,avg);
    }
    return avglist;
}

int main(){
    Node* mylist_head = new Node();
    int in;
    for(int i=0; i<12; i++){
        cin >> in;
        addNode(mylist_head, in);
    }
    Node* avg_list = get_average_list(mylist_head);
    display(mylist_head);
    display(avg_list);
    return 0;
}


