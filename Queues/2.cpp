// program to implement queue using 2 pointers using an array

#include<iostream>
using namespace std;

class Queue{
    private:
        int size;
        int rear;
        int front;
        int *A;
    public:
        Queue(int s){
            size = s;
            rear = -1; // yeh last wale element pe hoga
            front = -1; // sabse pehle wale element ke bhi aage hoga
            A = new int[size]();
        };
        void enqueue(int data){
            // O(1)
            rear++;
            A[rear] = data;
        };
        void dequeue(){
            // O(1)
            front++;
            A[front] = 0;
        };
        void print(){
            for(int i=front+1; i<=rear; i++){
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
            if( rear == front ){
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
    q.enqueue(6);  
    q.enqueue(10);  
    q.enqueue(14);
    q.print();
    q.dequeue();
    q.print(); 
}