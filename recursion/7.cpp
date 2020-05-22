// program to find the sum of first n numbers using recursion

#include<iostream>
using namespace std;

int sumH(int i){ // head recursion
    // base condition
    if(i<=0){
        return 0;
    };
    // recursive case
    return sumH(i-1)+i; // find sum till i-1 and then add i to it eg sum(4)+5 // easy to think of
};

int sumT(int i){  // tail recursion
    static int count = 0;
    // base case
    if(i<=0){
        return count;
    };
    // recursive case
    count = count + i;
    sumT(i-1); // go from i to 0 and keep adding it to count eg count=count+5, count = count+4 ...
};

int main(){
    int n;
    cout<<"Enter the no till which you need the sum :-"<<endl;
    cin>>n;

    cout<<"Using head recursion"<<endl;
    cout<<sumH(n)<<endl;

    cout<<"Using tail recursion"<<endl;
    cout<<sumT(n)<<endl;
}