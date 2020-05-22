// program to find power using recursion

#include<iostream>
using namespace std;

int power(int b, int p){
    // base case
    if(p == 1){
        return b;
    };
    // recursive case
    return power(b, p-1)*b;  // eg 2^5 = 2^4 * 2;
};

// more effective methord
int altPower( int b, int p){
    // base case
    if( p == 1 ){
        return b;
    };
    //recursive case

    // case 1:- power is even // 2^6 => 2^(2*3) => (2^2)^3 approach :- power(b*b, p/2)
    if( p%2 == 0 ){
        return altPower(b*b, p/2);
    }else{
        // case 2:- power is odd // 2^7 => 2*(2^6) => 2*{ ( 2^2 ) ^3 } approach :- b* power(b*b, (p-1)/2);
        return b*(altPower(b*b, (p-1)/2));
    };
}

int main(){
    int b, p;
    cout<<"enter the base :-"<<endl;
    cin>>b;
    cout<<"enter the power :-"<<endl;
    cin>>p;

    cout<<"using power function "<<power(b, p)<<endl;
    cout<<"using altPower function "<<altPower(b, p)<<endl;
}