// program to implement priority queue ( element priority )
// Dequeue operation takes O(n) time

#include<iostream>
#include<algorithm>
using namespace std;

int findMin(int A[], int n){
    int min = A[0];
    int index = 0;
    for(int i=0; i<=n; i++){
        if( min > A[i] ){
            min = A[i];
            index = i;
        }
    };
    return index;
};

class PrQueue{
    public:
        int size;
        int *A;
        int rear;

        PrQueue(int n){
            size = n;
            A = new int[size];
            rear = -1;
        };
        void enqueue(int x){
            rear++;
            A[rear] = x;
        };
        int dequeue(){
            int x;
            int index = findMin(A, rear);
            for(int i=index; i<rear; i++){
                swap(A[i], A[i+1]);
            };
            cout<<endl;
            x = A[rear];
            A[rear] = 0;
            rear--;
            return x;
        }; 

};

int main(){
    PrQueue q(5);
    q.enqueue(1);
    q.enqueue(5);
    q.enqueue(2);
    q.enqueue(9);
    q.enqueue(8);
    cout<<q.dequeue()<<" was removed"<<endl;
    cout<<q.dequeue()<<" was removed"<<endl;
    cout<<q.dequeue()<<" was removed"<<endl;
    cout<<q.dequeue()<<" was removed"<<endl;
    cout<<q.dequeue()<<" was removed"<<endl;
}