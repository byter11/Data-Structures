#include <bits/stdc++.h>

struct DNode{
    bool has_hidden_member;
    bool is_hijacked;
    DNode* next;
    DNode* prev;
    DNode():has_hidden_member(false),is_hijacked(false){ next = NULL; prev = NULL;}
};

void push(DNode*& head){
    if(!head){
        head = new DNode();
        return;
    }
    DNode* temp = head;
    while(temp->next)
        temp = temp->next;
    temp->next = new DNode();
    temp->next->prev = temp;
}
void view_cabins(DNode* head){
    std::cout << "Hijacked: ";
    DNode* temp = head;
    while(temp){
        std::cout << temp->is_hijacked << ' ';
        temp = temp->next;
    }
    std::cout << "\nHidden Member: ";
    while(head){
        std::cout << head->has_hidden_member << ' ';
        head = head->next;
    }
    std::cout << '\n';
}

void hijack(DNode* head){
    
    while(head){
        
        if(rand()%3 == 1 or !head->next){
            head->is_hijacked = true;
            break;
        }
        head = head->next;
    }
}
void hide_member(DNode* head){
    
    while(head){
        if(rand()%3 == 1 or !head->next ){
            head->has_hidden_member = true;
            break;
        }
        head = head->next;
    }
}
void find(DNode* head){
    int i=0;
    //Step 1. Search hijacked cabin
    while(head){
        if(head->is_hijacked){
            std::cout << "Hijacked cabin at Cabin " << i+1 << '\n';
            break;
        }
        head = head->next;
        i++;
    }
    //Go back to engine
    while(head->prev){
        head = head->prev;
        i--;
    }
    //Step 2. Search hidden member
    while(head){
        if(head->has_hidden_member)
            std::cout << "Hidden member found at Cabin " << i+1 << '\n';
        head = head->next;
        i++;
    }
}
int main(){
    srand(time(NULL));   
    DNode* engine = NULL;
    for(int i=1;i<10;i++)
       push(engine);

    hijack(engine);
    hide_member(engine);
    view_cabins(engine);

    find(engine);
}