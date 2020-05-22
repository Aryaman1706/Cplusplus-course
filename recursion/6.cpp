// program to demonstrate nested recursion

#include<iostream>
using namespace std;

int funct(int i){
    // base case
    if(i<=0){
        cout<<"end"<<endl;
        return 0;
    };
    // recursion case
    cout<<"i "<<i<<endl;
    funct(funct(i-1));
};

int main(){
    int n;
    cin>>n;
    funct(n);
}