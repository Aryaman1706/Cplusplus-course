// program to demonstrate try catch with base and derived class

#include<iostream>
using namespace std;

class Base {  };

class Derived : public Base {  };

int main(){
    int a, b;
    cin>>a>>b;

    try{
        if( a == 0 ) {
            throw Base();
        } else if ( b == 0 ) {
            throw Derived(); // this will basically throw error for both base and derived
        };
    } catch ( Derived ) { // this should come first because if base comes first it would catch the error thrown for derived also
        cout<<"error derived"<<endl;
    } catch ( Base ) {
        cout<<"error base"<<endl;
    }
}