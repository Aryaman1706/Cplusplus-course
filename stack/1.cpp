// program to impement stack using array

#include<iostream>
using namespace std;

class Stack{
    private:
        int* A;
        int size;
        int top;
    public:
        Stack(int n){
            size = n;
            top = -1;
            A = new int [size];
        };
        void isFull(){
            if ( top == size-1 ){
                cout<<"Stack is full :<"<<endl;
            }
        };
        void isEmpty(){
            if(top == -1){
                cout<<"Hey!! Stack is Empty..."<<endl;
            }
        };
        void push(int x){
            if( top < size){
                top++;
                A[top] = x;
            }else{
                cout<<"Stack is full.. delete some items"<<endl;
            }
        };
        void pop(){
            if ( top == -1 ){
                cout<<"Stack is already empty.. Insert some items"<<endl;
            }else{
                cout<<A[top]<<" is removed"<<endl;
                A[top] = NULL;
                top--;
            }
        };
        void peek(int i){
            cout<<"Value at "<<i<<" is "<<A[size-i]<<endl;
        };
        void stackTop(){
            cout<<"Value at top of stack is "<<A[top]<<endl;
        };
        void display(){
            int i = top;
            while(i >= 0){
                cout<<A[i]<<" ";
                i--;
            }
            cout<<endl;
        };
};

int main(){
    int n;
    cout<<"Enter the size of stack"<<endl;
    cin>>n;
    Stack S(n);
    int x;
    for(int i=0; i<n; i++){
        cout<<"Enter number to insert"<<endl;
        cin>>x;
        S.push(x);
    };
    S.isFull();
    S.peek(5);
    S.stackTop();
    for(int i=0; i<n; i++){
        S.pop();
    };
    S.isEmpty();
    S.display();
}