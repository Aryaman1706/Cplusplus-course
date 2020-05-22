// program to demonstrate head recursion

#include<iostream>
using namespace std;

int sum(int i){
    static int count = 0;
    // base condition
    if(i<=0){
        return 0; // basically the sum of number after 0 which we do not want
    };
    // recursive case
    cout<<"i "<<i<<endl;
    cout<<"count "<<count<<endl;
    return sum(i-1) + i; // it is like saying find the sum till 4 and then add 5 to it
};

int main(){
    int n;
    cout<<"enter the no :-"<<endl;
    cin>>n;
    cout<<sum(n);
}