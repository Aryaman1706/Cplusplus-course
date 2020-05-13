// program to demonstrate try and catch amongst function

#include<iostream>
using namespace std;

int division ( int a, int b ) {
    if( b == 0 ) {
        throw 1;
    };
    return a/b;
};

int main(){
    int a, b, c;
    cin>>a>>b;
    try {
        c = division( a, b );
        cout<<"Result "<<c<<endl;
    } catch ( int e ) {
        cout<<"Division by zero is not possible"<<endl;
    }
    cout<<"End..."<<endl;
}