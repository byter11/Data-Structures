#include "List.h"

void List::display(){
  Node* temp = head;
      while(temp != NULL && temp->next != head){
        cout << temp->data << ' ';
        temp = temp->next;
      }
      
    cout << '\n';
}
int List::count(int searchFor){
      Node* temp = head;
      int count = 0;
      if( temp->data == searchFor)
        count++;
      while(temp->next != NULL){
        if( temp->next->data == searchFor )
          count++;
        temp = temp->next;
    }
    return count;
}

void List::reverseList() {
    Node* temp = head;
    Node* nextnode = NULL;
    Node* revnode = NULL;
    while (temp != NULL) {
        head = temp;
        nextnode = temp->next;
        temp->next = revnode;
        revnode = temp;
        temp = nextnode;
  } 
}
void List::copyList(List* newlist){

      newlist->head = new Node();
      Node* temp = head;
      while(temp->next != NULL){
        newlist->addNode(temp->data);

        temp=temp->next;
      }
}
void List::makeCircular(){
  Node* temp = head;
      while(temp->next != NULL){
        temp = temp->next;
      }
    temp->next = head;
}
bool List::isCircular(){
      if(head == NULL)
        return false;
      Node* temp = head->next;
      while(temp != NULL && temp != head){
        temp = temp->next;
      }
      if(temp == head)
        return true;
      return false;
}
bool List::compare(List list){
      Node* thisList = head;
      Node* listhead = list.head;
      while(listhead != NULL and thisList != NULL ){
        //Double Check if one of them is NULL
        if(listhead == NULL or thisList == NULL){
          return false;
        }
        if(thisList->data != listhead->data){
          return false;
        }
        listhead = listhead->next;
        thisList = thisList->next;
      }
      return true;
}
void List::deleteList(){
      head->next = NULL;
      delete head;
}
void List::addNode(int val){
      Node* newnode = new Node();
      newnode->data = val;
      if( head == NULL ){
        head = newnode;
        return;
      }
      Node* temp = head;
      while(temp->next != NULL && temp->next != head){
        temp = temp->next;
      }
      //newnode->next = head;
      temp->next = newnode; 
}
void List::delNode(int idx){
  if(head == NULL)
    return;
  if(idx == 0 or head->next==NULL){
    head = head->next;
    return;
  }
  Node* tmp = head;
  for(int i=0;i<idx-1; i++ ){

    tmp = tmp->next;
    if(tmp->next == NULL) 
      return;
  }
  if(tmp->next->next == NULL)
    tmp->next = NULL;
  else{
    tmp->next = tmp->next->next;
  }
}
void List::insertNode(int idx, int val){
  Node* newnode = new Node();
  newnode->data = val;

  if(head == NULL)
    return;
  if(idx == 0 or head->next==NULL){
    newnode->next = head;
    head = newnode;
    return;
  }
  Node* tmp = head;
  for(int i=0;i<idx-1; i++ ){
    tmp = tmp->next;
    if(tmp->next == NULL){
      tmp->next = newnode;
      return;
    }
  }
  Node* nextnode = tmp->next;
  tmp->next = newnode;
  tmp->next->next = nextnode;
}
bool List::searchNode(int val){
  Node* temp = head;
      while(temp != NULL){
        if(temp->data == val)
          return true;
        temp = temp->next;
      }
    return false;
}
