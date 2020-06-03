// program to change infix to postfix using stack

#include<iostream>
#include<cstring>
using namespace std;

class Stack{
    private:
        int size;
        int top;
        char *A;
    public:
        Stack(int n){
            size = n;
            top = -1;
            A = new char[n];
        };
        void push(char ch){
            top++;
            A[top] = ch;
        };
        char pop(){
            char temp;
            temp = A[top];
            A[top] = NULL;
            top--;
            return temp;
        };
        bool isEmpty(){
            if( top == -1){
                return true;
            }else{
                return false;
            }
        };
};

int main(){
    string A;
    cin>>A;
}