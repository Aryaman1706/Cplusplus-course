/*0000 IMPORTANT 0000*/
// program to calculate sum of tylor series using recursion ( horner's methord )

/*APPROACH ------------>*/
// e^x = 1 + x^1/1! + x^2/2! + x^3/3! + x^4/4! ...n terms // power and factorial was increasing
// e^x = 1 + x/1 { 1 + x/2 + x^2/6 + x^3/24 }
// e^x = 1+ x/1 { 1+ x/2 { 1+ x/3 + x^2/12 } }
// e^x = 1 + x/1 { 1+ x/2 { 1 + x/3 { 1 + x/4 } } } // only denominator is increasing

// general formulae => s = 1+ x*s/(n-1)  here s will start from 1 and will be updated for every reduced n
/*APPROACH ------------>*/

#include<iostream>
using namespace std;

double e(int x, int n){
    static double s = 1;
    // base case
    if(n == 1){
        return s;
    }
    // recursive case
    s = 1 + x*s/(n-1);
    return e(x,n-1);
}

int main(){
    int x, n;
    cout<<"enter the value of x :-"<<endl;
    cin>>x;
    cout<<"enter the value of n :-"<<endl;
    cin>>n;

    cout<<e( x, n );
}