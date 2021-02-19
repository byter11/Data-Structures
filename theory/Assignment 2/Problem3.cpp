#include <bits/stdc++.h>
using namespace std;
#define EXPSIZE 80

static char OPERATORS[7] = {'-','+','|','*','/','|','^'};

struct SNode{
    char data; 
    SNode* next; 
    SNode(int d){ 
        data = d; 
        next = NULL; 
    }
};

class Stack{
    public:
    SNode* top;
    Stack(){ top = NULL; }

    void push(char x){
        if(!top){
            top = new SNode(x);
            top->next = NULL;
            return;
        }
        SNode* newtop = new SNode(x);
        newtop->next = top;
        top = newtop;
        
    }
    char pop(){
        if(!top)
            return 0;
        char data = top->data;
        top = top->next;
        return data;
    }
    char peek(){
        if(!top)
            return 0;
        return top->data;
    }
    bool isEmpty(){
        return top == NULL;
    }
};
void reverse(char (&arr)[EXPSIZE] , size_t s){
    int start=0, end=s;
    while(start < end){   
        char temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

bool isOperator(char c){
    for(char o : OPERATORS)
        if(c == o)
            return true;
    return false;
}

int operatorPriority(char c, char o){
    int ci=-1, oi=-1;
    for(int i=0; i<7; i++){
        if(c == OPERATORS[i])
            ci = i;
        if(o == OPERATORS[i])
            oi = i;
    }
    return ci-oi;
}

void toPrefix(char (&exp)[EXPSIZE]){
    Stack s;
    reverse(exp, strlen(exp)-1 );
    char pre[EXPSIZE] = {'\0'};
    int j=0;

    for(char c: exp){
        if(c=='\0') break;

        else if(c == ')'){
            s.push(c);
        }

        else if(c == '('){
            while(!s.isEmpty()){
                char o = s.pop();
                if( o == ')')
                    break;
                pre[j++] = o;
            }
        }

        else if(isOperator(c)){
            char top = s.peek();
            while(!s.isEmpty() && operatorPriority(c,top) < -1 ){
                    pre[j++] = s.pop();
                    top = s.peek();
                }
            s.push(c);
        }

        else
            pre[j++] = c;
    }

    while(!s.isEmpty())
        pre[j++] = s.pop();

    reverse(pre, strlen(pre)-1);
    reverse(exp, strlen(exp)-1);

    cout << "Prefix Notation: ";
    for(char c: pre){
        if(c=='\0') break;
        cout << c;
    }
    cout << '\n';
}

void toPostfix(char (&exp)[EXPSIZE]){
    cout << "Postfix Notation: ";

    Stack s;
    char pre[EXPSIZE];

    for(char c: exp){
        if(c=='\0') break;

        if(c == '(')
            s.push(c);
        
        else if(isOperator(c)){
            char top = s.peek();
            while( !s.isEmpty() && top!='(' && operatorPriority( c, top ) <= 1){
                cout << s.pop();
                top = s.peek();
            }
            s.push(c);
        }

        else if(c==')'){
            while(!s.isEmpty()){
                char o = s.pop();
                if(o == '(')
                    break;
                cout << o;
            }
        }
        else
            cout << c;    
    }
    
    while(!s.isEmpty())
            cout << s.pop();
    
    cout << '\n';
}

int main(){
    char exp[EXPSIZE];
    string dir = "./A2UpdatedTestCases/A2P3/";
    fstream in;

    for(int i=0; i<=5; i++){
        string file = dir + "input00" + to_string(i) + ".txt";
        in.open(file, ios::in);
        in >> exp;
        cout << "Test Case#" << i << ": ";
        for(char c : exp){
            if(c=='\0') break;
            cout << c;
        }
        cout << '\n';
        toPrefix(exp);
        toPostfix(exp);
        in.close(); 
        fill(exp, exp+EXPSIZE, '\0');
        cout << '\n';
    }
    

    

    return 0;
}