struct DoublyNode{
    int num;
    DoublyNode* prev;
    DoublyNode* next;
    
    DoublyNode(int num):num(num){
        prev = NULL;
        next = NULL;
        }
};

class DoublyList{
    
    DoublyNode* head;
    void swap(DoublyNode* n1, DoublyNode* n2){
        if(!n1 || !n2)
            return;

        if(n1 == head){
            head = n2;
            n2->prev->next = n1;
        }
        else if(n2 == head){
            head = n1;
            n1->prev->next = n2;
        }
        if(n1->next == n2){
            DoublyNode* temp = n2->next;
            n2->prev = n1->prev;
            n2->next = n1;
            n1->prev->next = n2;
            n1->prev = n2;
            n1->next = temp;
            return;
        } 
        DoublyNode* tp = n2->prev, *tn = n2->next;
        n2->prev = n1->prev;
        n2->next = n1->next;
        n1->prev = tp;
        n1->next = tn;
        head->prev = NULL;
        
    }
    public:
    void cheez(){
        swap(head, head->next);
    }
    DoublyList(){head = NULL;}
    DoublyList(DoublyList& s){
        if(!s.head)
            return;
        head = NULL;
        head = new DoublyNode(s.head->num);
        DoublyNode* temp = head;
        DoublyNode* shead = s.head;
        while(shead->next){
            this->push(shead->num);
        }
    }
    
    void print(){
        DoublyNode* temp = head;
        while(temp){
            std::cout << temp->num << ' ';
            temp = temp->next;
        }
        std::cout << '\n';
    }
    void push(int num){
        if(!head){
            head = new DoublyNode(num);
            return;
        }
        DoublyNode* temp = head;
        while(temp->next)
            temp = temp->next;
        temp->next = new DoublyNode(num);
        temp->next->prev = temp;
    }
    void SelectionSort(){
        DoublyNode *outer = head, *inner, *min;

        while(outer){
            cout << outer->num;
            min = outer;
            inner = outer->next;
            while(inner){
                if(inner->num < min->num)
                    min = inner;
                inner = inner->next;
            }
            DoublyNode* next = outer->next;
            if(outer != min)
                swap(outer, min);
            
            outer = next;
        }   
    }
};