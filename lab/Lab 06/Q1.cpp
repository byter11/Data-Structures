#include<iostream>
#include<cassert>
struct Node{
    int data;
    Node* next;
    Node(){}
    Node(int data):data(data){next = NULL;}
};

void push(Node* head, int data){
        if(!head)
            head->data = data;
        else{
            while(head->next)
                head = head->next;
            head->next = new Node(data);
        }
}
void display(Node* head){
    while(head){
        std::cout << head->data << ' ';
        head = head->next;
    }
    std::cout << '\n';
}
int GetNth(Node* head, int idx){
    assert(head != NULL);
    if(idx == 0)
        return head->data;
    while(idx-- && head->next){
        head = head->next;
    }
    assert(idx==-1);
    if(head)
        return head->data;
    
}

int main(){
    Node* head = new Node(1);
    for(int i=2;i<11;i++){
        push(head, i);
    }
    display(head);

    std::cout << GetNth(head, 0) << '\n';
    std::cout << GetNth(head, 9) << '\n';
    std::cout << GetNth(head, 10) << '\n';
    return 0;
}