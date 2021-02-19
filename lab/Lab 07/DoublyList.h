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
    void OrderedSwap(DoublyNode* n1, DoublyNode* n2){
        if(!n1 || !n2 || n1==n2)
            return;
        if(n1 == head){
            head = n2;
        }
        else{
            n1->prev->next = n2;
            
        }
        
        // else if(n2 == head){
        //     head = n1;
        //     n1->prev->next = n2;
        // }
        if(n1->next == n2){
            DoublyNode* temp = n2->next;
            n2->prev = n1->prev;
            n2->next = n1;
            n1->prev = n2;
            n1->next = temp;
            return;
        }
        n1->next->prev = n2;
        n2->prev->next = n1;
        if(n2->next)
            n2->next->prev = n1;
        DoublyNode *tp = n2->prev, *tn = n2->next;
        n2->prev = n1->prev;
        n2->next = n1->next;
        n1->prev = tp;
        n1->next = tn;
        head->prev = NULL;
    }
    public:
    void cheez(){
        swap(head->next, head->next->next->next->next->next->next->next->next->next);
    }
    DoublyList(){head = NULL;}
    
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
            //cout << outer->num;
            min = outer;
            inner = outer->next;
            while(inner){
                if(inner->num < min->num)
                    min = inner;
                inner = inner->next;
            }
            DoublyNode* next = outer->next==min ? outer : outer->next;
            OrderedSwap(outer, min);
            outer = next;
        }   
    }
    void InsertionSort(){
        DoublyNode *outer=head->next, *key, *inner, *next;
        while(outer){
            key = outer;
            inner = outer->prev;
            next = outer->next;
            while(inner && inner->num > key->num){
                inner = inner->prev;
            }
            if(inner == key)
                continue;
            key->prev->next = key->next;
            if(key->next)
                key->next->prev = key->prev;
            
            if(!inner){
                key->next = head;
                key->prev = NULL;
                head->prev = key;
                head = key;
            }
            else{
                DoublyNode *n = inner->next;
                if(n)
                    n->prev = key;
                inner->next = key;
                key->next = n;
                key->prev = inner;
            }
                outer = next;
        }
    }
};