// program to demonstrate tree recursion

#include<iostream>
using namespace std;

void funct (int i){
    // base case
    if(i<=0){
        cout<<"end"<<endl;
        return;
    };
    // recursive case
    cout<<"n "<<i<<endl;
    funct(i-1);
    // funct(i-1);
    funct(i-2);

}

int main(){
    int n;
    cin>>n;
    funct(n);
}