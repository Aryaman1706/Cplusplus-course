// program to find nCr using recursion
// nCr = (n-1)C(r-1) + (n-1)C(r)

#include<iostream>
using namespace std;

int ncr (int n, int r){
    if( r == n || r == 0 ){
        return 1;
    }

    return ncr(n-1, r-1) + ncr(n-1, r); 
};

int main(){
    int n, r;
    cout<<"Enter the value of n"<<endl;
    cin>>n;
    cout<<"Enter the value of r"<<endl;
    cin>>r;

    cout<<"Result"<<endl;
    cout<<ncr(n, r);
}