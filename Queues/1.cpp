// program to implement queue using single pointer using an array

#include<iostream>
#include<algorithm>
using namespace std;

class Queue {
    private:
        int size;
        int rear;
        int *A;
    public:
        Queue(int s){
            size = s;
            A = new int[s]();
            rear = -1;
        };
        void enqueue(int data){
            // O(1)
            rear++;
            A[rear] = data;
        };
        void dequeue(){
            // O(n)
            A[0] = 0;
            for(int i=0; i<rear; i++){
                swap(A[i], A[i+1]);
            };
            rear--;
        };
        void print(){
            for(int i=0; i<=rear; i++){
                cout<<A[i]<<" <- ";
            };
            cout<<"End"<<endl;
        };
        bool isFull(){
            if(rear == size-1){
                return true;
            }else{
                return false;
            }
        };
        bool isEmpty(){
            if(rear == -1){
                return true;
            }else{
                return false;
            }
        };
};

int main(){
    int n;
    cout<<"Enter the size of queue"<<endl;
    cin>>n;
    Queue q(n);
    q.enqueue(5);
    q.enqueue(7);
    q.enqueue(9);
    q.enqueue(15);
    q.print();
    q.dequeue();
    q.print();
    cout<<q.isEmpty()<<endl;
}