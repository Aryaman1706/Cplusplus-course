// program to implement stack using linked list

#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
};

class Stack{
    private:
        Node* top;
    public:
        Stack(){
            top = NULL;
        };
        void push(int x){
            Node* t = new Node();
            t->data = x;
            t->next = top;
            top = t;
        };
        void pop(){
            Node* t = top;
            top = top->next;
            delete t;
        };
        void display(){
            Node* t=top;
            while(t != NULL){
                cout<<t->data<<" ";
                t = t->next;
            };
            cout<<"End"<<endl;
        };
        void isEmpty(){
            if( top == NULL){
                cout<<"Stack is empty"<<endl;
            }
        };
        void isFull(){
            // since ll has no fixed size hence stack would be full when heap is full
            // that is you can not make a new node
            Node* t= new Node();
            if( t == NULL){
                cout<<"Stack is full"<<endl;
            }
        };
        void peek(int pos){
            Node* t = top;
            for(int i=0; i<pos-1; i++){
                t = t->next;
            };
            cout<<"Value at position "<<pos<<" is "<<t->data<<endl;
        }
};

int main(){
    Stack S;
    S.isEmpty();
    S.push(1);
    S.isEmpty();
    S.push(2);
    S.push(3);
    S.push(4);
    S.push(5);
    S.display();
    S.pop();
    S.display();
    S.peek(4);
}