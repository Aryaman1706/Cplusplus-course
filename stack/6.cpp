// implementing stack with circular doubly linked list

#include<iostream>
#include<map>
#include<cstring>
using namespace std;

class Node{
    public:
        char data;
        Node* next;
        Node* prev;
};

class Stack{

    public:
        Node* top;
        Stack(){
            top = NULL;
        };
        void push(char ch){
            if( top == NULL ){
                Node* p = new Node();
                p->data = ch;
                top = p;
                top->next = top;
                top->prev = top;
            }else{
                Node* p = new Node();
                p->data = ch;
                p->next = top;
                p->prev = top->prev;
                top->prev->next = p;
                top->prev = p;
                top = p;
            }
        };
        void pop(){
            if(top->next == top){
                Node* p = top;
                top = NULL;
                delete p;
            }else{
                Node* p = top;
                p->prev->next = p->next;
                p->next->prev = p->prev;
                top = top->next;
                delete p;
            };
            
        };
        void print(int pos){
          Node* p = top;
          p = p->prev;
          for(int i=0; i<pos-1; i++){
              p = p->prev;
          };
          cout<<p->data<<endl;  
        };
        bool isEmpty(){
            if( top == NULL){
                return true;
            }else{
                return false;
            };
        };
        int size(){
            Node* p = top;
            int count = 0;
            do{
                count++;
                p = p->next;
            }while( p != top );
            return count;
        }
};
void copyStack(Stack& A, Stack& B){
    while(A.isEmpty() == false){
        A.pop();
    };
    Node* p = B.top;
    p = p->prev;
    for(int i=0; i<B.size(); i++){
        A.push(p->data);
        p = p->prev;
    }
};
int main(){
    Stack S;
    int changes = 0;
    map<int, Stack> mymap;
    int g;
    cin>>g;
    for(int q=0; q<g; q++){
        int op;
        cin>>op;
        if(op == 1){
            // append
            string w;
            cin>>w;
            for(int i=0; i<w.length(); i++){
                S.push(w[i]);
            };
            changes++;
            Stack copy;
            copyStack(copy, S);
            mymap[changes] = copy;
        }else if(op == 2){
            // delete
            int k;
            cin>>k;
            for(int j=0; j<k; j++){
                S.pop();
            };
            changes++;
            Stack copy;
            copyStack(copy, S);
            mymap[changes] = copy;
        }else if( op == 3 ){
            // print
            int k2;
            cin>>k2;
            S.print(k2);            
        }else {
            // undo
            changes--;
            copyStack(S, mymap[changes]);
        }
    }
}