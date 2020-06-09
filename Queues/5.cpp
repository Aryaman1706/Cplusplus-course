// program to implement DEqueue using arrays

#include<iostream>
using namespace std;

class DEqueue{
    private:
        int front;
        int rear;
        int *A;
        int size;
    public:
        DEqueue(int n){
            size = n;
            front = -1;
            rear = -1;
            A = new int [size];
        };
        bool isEmpty(){
            if( front == rear ){
                return true;
            }else{
                return false;
            }
        };
        bool isFull(){
            if( rear == size-1 ){
                return true;
            }else{
                return false;
            }
        };
        void enqueueFront(int x){
            if( front == -1 ){
                cout<<"can not enqueue front"<<endl;
            }else{
                A[front] = x;
                front--;
            }
        };
        void enqueueRear(int x){
            if( isFull() ){
                cout<<"Queue is full can not enqueue anymore"<<endl;
            }else{
                rear++;
                A[rear] = x;
            }
        };
        void dequeueFront(){
            int x = 0; 
            if( isEmpty() ){
                cout<<"Queue is already empty"<<endl;
            }else{
                front++;
                x = A[front];
                A[front] = 0;
                cout<<x<<" was removed"<<endl;
            }
        };
        void dequeueRear(){
            int x = 0;
            if( isEmpty() ){
                cout<<"Queue is already empty"<<endl;
            }else{
                x = A[rear];
                A[rear] = 0;
                rear--;
                cout<<x<<" was removed"<<endl;
            }
        };
        void print(){
            for(int i= front+1; i<=rear; i++){
                cout<<A[i]<<" <- ";
            };
            cout<<"End"<<endl;
        };
};

int main(){
    int n;
    cin>>n;
    DEqueue q(n);
    q.enqueueRear(8);
    q.enqueueRear(9);
    q.enqueueRear(10);
    q.dequeueFront();
    q.dequeueFront();
    q.enqueueFront(6);
    q.dequeueRear();
    q.enqueueFront(7);
    q.print();
}