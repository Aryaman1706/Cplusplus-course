// program is to calculate sum of taylor series using recursion ( Simpler approach )
// e^x = 1 + x^1/1! + x^2/2! + x^3/3! + ...n terms

#include<iostream>
using namespace std;

double e(int x, int n){
    static double p = 1, f =1;
    double r; 
    // base case
    if(n==1){
        return 1;
    }
    // recursive case
    r = e(x, n-1); // why here? because we want to update and add p/f after the value of e(x,n-1) is computed // it is basically blocking the code such that p and f are updated after
    p = p*x;
    f = f*(n-1);
    return r + (p/f);
    // return e(x, n-1) + (p/f); // why not this?
}

int main(){
    int x, n;
    cout<<"enter the value of x :-"<<endl;
    cin>>x;
    cout<<"enter the value of n :-"<<endl;
    cin>>n;

    cout<<e( x, n );
}