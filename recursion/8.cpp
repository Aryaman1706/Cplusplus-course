// program to find factorial of n using recursion

#include<iostream>
using namespace std;

int factorial(int i){
    // base case
    if(i<=0){
        return 1;
    };
    // recursive case
    return factorial(i-1)*i; // approach :- find factorial till i-1 and then multiply it bt i eg 5! = 4! * 5
};

int main(){
    int n;
    cout<<"enter the number :-"<<endl;
    cin>>n;
    cout<<factorial(n);
    factorial(n);
}