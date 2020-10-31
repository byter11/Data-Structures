
struct Node{
  int data;
  struct Node* next;
};

class List{
  Node* head;
  public:
    List(){
      head = NULL;
    }
    void display();
    int count(int);
    void reverseList();
    void copyList(List*);
    void makeCircular();
    bool isCircular();
    bool compare(List);
    void deleteList();
    void addNode(int);
    void delNode(int);
    void insertNode(int,int);
    bool searchNode(int);
};