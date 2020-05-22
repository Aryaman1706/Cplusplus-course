// program to demonstrate indirect recursion
// here functA calls functB and then functB calls functA ( A -> B -> A )

#include<iostream>
using namespace std;

void functB(int i);  // this is just the defination

void functA(int i){
    // base condition
    if(i<=0){
        cout<<"end"<<endl;
        return;
    };
    // recursive case
    cout<<"i "<<i<<endl;
    functB(i-1);
};

void functB(int i){
    // base case
    if(i<1){
        cout<<"end"<<endl;
        return;
    };
    // recursive case
    cout<<"i "<<i<<endl;
    functA(i/2);
};

int main(){
    int n;
    cin>>n;
    functA(n);
}