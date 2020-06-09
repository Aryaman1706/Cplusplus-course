// program to implement queue using linked list

#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
};

class Queue{
    private:
        Node* front;
        Node* rear;
    public:
        Queue(){
            front = NULL;
            rear = NULL;
        };
        void enqueue(int x){
            Node* t = new Node();
            t->data = x;
            t->next = NULL;
            
            if ( front == NULL ){
                front = t;
                rear = t;
            }else{
                rear->next = t;
                rear = t;
            }
        };
        void dequeue(){
            Node* p = front;
            front = front->next;
            int x = p->data;
            cout<<x<<" was removed"<<endl;
            delete p; 
        };
        bool isEmpty(){
            if( front == NULL ){
                return true;
            }else{
                return false;
            }
        };
        bool isFull(){
            // full only when heap is full
            Node* t = new Node();
            if( t == NULL ){
                // this means that node is not created
                return true;
            }else{
                return false;
            }
        };
        void print(){
            Node* p = front;
            while( p != NULL ){
                cout<< p->data<<" <- ";
                p = p->next;
            };
            cout<<"End"<<endl;
        };
};

int main(){
    Queue q;
    cout<<q.isEmpty()<<endl;
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(8);
    q.enqueue(10);
    q.enqueue(15);
    q.enqueue(18);
    q.print();
    q.dequeue();
    cout<<q.isEmpty()<<endl;
    cout<<q.isFull()<<endl;
}