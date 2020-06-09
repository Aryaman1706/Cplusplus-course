// program to implement queue using 2 stacks

#include<iostream>
using namespace std;

class Stack{
    public:
        int size; 
        int top;
        int* A;
        Stack(int n){
            size = n;
            A = new int[size];
            top = -1;
        };
        void push(int x){
            top++;
            A[top] = x;
        };
        int pop(){
            int x;
            x = A[top];
            A[top] = 0;
            top--;
            return x;
        };
        bool isEmpty(){
            if(top == -1){
                return true;
            }else{
                return false;
            }
        };
};

Stack S1(5);
Stack S2(5);

class Queue{
    private:
        int size;
    public:
        Queue(int n){
            size = n;
        };
        void enqueue(int data){
            S1.push(data);
        };
        void dequeue(){
            if( S2.isEmpty() ){
                while ( !S1.isEmpty() ){
                    S2.push(S1.pop());
                };
            };
            cout<<S2.pop()<<" was removed"<<endl;
        };
        void print(){
            while( !S2.isEmpty() ){
                cout<<S2.pop()<<" <- "; 
            };
            while( !S1.isEmpty() ){
                S2.push(S1.pop());
            };
            while( !S2.isEmpty() ){
                cout<<S2.pop()<<" <- "; 
            };
            cout<<"End"<<endl;
        };
};

int main(){
    Queue q(5);
    q.enqueue(8);
    q.enqueue(9);
    q.enqueue(10);
    q.dequeue();
    q.enqueue(11);
    q.enqueue(12);
    q.enqueue(17);
    q.print();
}