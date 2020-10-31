struct SinglyNode{
    int num;
    SinglyNode* next;
    SinglyNode(int num):num(num){next = NULL;}
};
class SinglyList{
    
    SinglyNode* head;
    void swap(SinglyNode* prev1, SinglyNode* prev2){
        SinglyNode* n1 = prev1 ? prev1->next : head;
        SinglyNode* n2 = prev2 ? prev2->next : head;

        if(prev1)
            prev1->next = n2;
        else
            head = n2;
        if(prev2)
            prev2->next = n1;
        else
            head = n1;
        
        SinglyNode* temp = n1->next;
        n1->next = n2->next;
        n2->next = temp;
    }
    public:
    SinglyList(){head = NULL;}
    SinglyList(SinglyList& s){
        if(!s.head)
            return;
        head = NULL;
        head = new SinglyNode(s.head->num);
        SinglyNode* temp = head;
        SinglyNode* shead = s.head;
        while(shead->next){
            temp->next = new SinglyNode(shead->next->num);
            shead = shead->next;
            temp = temp->next;
        }
    }
    
    void print(){
        SinglyNode* temp= head;
        while(temp){
            std::cout << temp->num << ' ';
            temp = temp->next;
        }
        cout << '\n';
    }
    void push(int num){
        if(!head){
            head = new SinglyNode(num);
            return;
        }
        SinglyNode* temp = head;
        while(temp->next)
            temp = temp->next;
        temp->next = new SinglyNode(num);
    }
    void BubbleSort(){
        if(!head) return;
        SinglyNode *outer=head, *inner;
        while(outer){
            inner = head;
            while(inner->next->next){
                if(inner->next->num > inner->next->next->num)
                    swap(inner, inner->next);
                inner = inner->next;
            }
            if(head->num > head->next->num){
                swap(NULL, head);
                outer = head;
            }
            else
                outer = outer->next;
        }
    }
};