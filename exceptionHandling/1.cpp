// program to display a simple try catch block

#include<iostream>
using namespace std;
int main(){
    int a, b, c;
    cin>>a>>b;
    try{
        if( b == 0 ) {
            throw 1;
        };
        c = a/b;
        cout<<"Result "<<c<<endl;
    } catch ( int e ) {
        cout<<"Division by zero is not possible"<<endl;
    }

    cout<<"End..."<<endl;
}