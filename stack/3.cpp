// program to check if paranthesis are balanced using Stack
// ((a+b)*(c-d))

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
        void pop(){
            A[top] = NULL;
            top--;
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
    string s;
    cin>>s;
    Stack stack(s.length());
    for(int i=0; i<s.length(); i++){
        if( s[i] == '(' ){
            stack.push('(');
        }else if( s[i] == ')' ){
            if( stack.isEmpty() == false ){
                stack.pop();
            }else{
                cout<<"Not Balanced"<<endl;
                return 0;
            }
        }
    }
    if ( stack.isEmpty() == false ){
        cout<<"Not balanced"<<endl;
    }else{
        cout<<"Balanced"<<endl;
    }
}