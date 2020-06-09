// program to implement circular queue using array

#include<iostream>
using namespace std;

class Queue {
    private:
        int front;
        int rear;
        int size;
        int *A;
    public:
        Queue(int n){
            size = n+1;
            front = 0;
            rear = 0;
            A = new int[size]();
        };
        void enqueue( int data ){
            if( ( (rear+1)%(size) ) == front ){
                cout<<"Queue is Full"<<endl;
            }else{
                rear = (rear+1)%(size);
                A[rear] = data;
            }
        };
        void dequeue(){
            front = (front+1)%(size);
            A[front] = 0;
        };
        void print(){
            int i = front+1;
            do{
                cout<<A[i]<<" <- ";
                i = (i+1)%size;
            } while ( i != (rear+1)%size );
            cout<<"End"<<endl;
        };
        bool isFull(){
            if( ((rear+1)%(size)) == front ){
                return true;
            }else{
                return false;
            }
        };
        bool isEmpty(){
            if(front == rear ){
                return true;
            }else{
                return false;
            }
        };
};

int main(){
    int n;
    cin>>n;
    Queue q(n);
    q.enqueue(5);
    q.enqueue(5);
    q.enqueue(5);
    q.enqueue(5);
    q.enqueue(5);
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.enqueue(5);
    q.enqueue(5);
    q.enqueue(5);
    q.print();
} 