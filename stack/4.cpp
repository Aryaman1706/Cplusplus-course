// program to check bracket balance in stack
// {(a+b)*[(c/d)+(e/f)]}

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

void isBalanced(string a){

    Stack S(a.length());
    for(int i=0; i<a.length(); i++){
        if( a[i] == '{' || a[i] == '[' || a[i] == '(' ){
            S.push(a[i]);
        }else if ( a[i] == '}' || a[i] == ']' || a[i] == ')' ){
            if ( S.isEmpty() == true ){
                cout<<"NO"<<endl;
                return;
            }else{
                if( a[i] == '}' ){
                    if( S.pop() != '{' ){
                        cout<<"NO"<<endl;
                        return;
                    }
                } else if( a[i] == ']' ){
                    if( S.pop() != '[' ){
                        cout<<"NO"<<endl;
                        return;
                    }
                } else if ( a[i] == ')' ){
                    if( S.pop() != '(' ){
                        cout<<"NO"<<endl;
                        return;
                    }
                }
            }
            
        }
    }
    if( S.isEmpty() == true ){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    };
}

int main(){
    int x;
    cin>>x;
    for(int i=0; i<x; i++){
        string a;
        cin>>a;
        isBalanced(a); 
    }
    return 0;
}