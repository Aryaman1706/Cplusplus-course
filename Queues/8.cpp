// program to implement priority queue ( element priority )
// Enqueue operation takes O(n) time

#include<iostream>
#include<algorithm>
using namespace std;

class PrQueue{
    public:
        int size;
        int *A;
        int rear;

        PrQueue(int n){
            size = n;
            A = new int[size]();
            rear = -1;
        };
        void enqueue(int x){
            if( x <= A[rear] ){
                rear++;
                A[rear] = x;
            }else{
                int i = rear;
                while( x > A[i] && i >= 0 ){
                    swap(A[i], A[i+1]);
                    i--;
                };
                i++;
                A[i] = x;
                rear++;
            };
        };
        int dequeue(){
            int x;
            x = A[rear];
            A[rear] = 0;
            rear--;
            return x;
        }; 
};

int main(){
    PrQueue q(5);
    q.enqueue(12);
    q.enqueue(5);
    q.enqueue(7);
    q.enqueue(2);
    q.enqueue(20);
    cout<<q.dequeue()<<" was removed"<<endl;
    cout<<q.dequeue()<<" was removed"<<endl;
    cout<<q.dequeue()<<" was removed"<<endl;
    cout<<q.dequeue()<<" was removed"<<endl;
    cout<<q.dequeue()<<" was removed"<<endl;
}