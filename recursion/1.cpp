// program to demonstrate basic recursion

#include<iostream>
using namespace std;

void funct (int i){
    // base condition
    if(i<=0){
        return;
    };
    // recursive case
    cout<<i<<endl;
    funct(i-1);
    
};

int main(){
    int n;
    cin>>n;
    funct(n);
}