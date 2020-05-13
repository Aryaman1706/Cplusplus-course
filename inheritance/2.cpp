// program to demonstrate how the constructors are executed in case of inheritance

#include<iostream>
using namespace std;

// base class
class Base {
    public:
        Base(){
            cout<<"Default constructor of base class"<<endl;
        };
        Base( int x ) {
            cout<<"Parameterized constructor of base class "<<x<<endl;
        };
};

// derived class
class Derived : public Base{
    public:
        Derived(){
            cout<<"Default constructor in derived"<<endl;
        };
        Derived( int y ) {
            cout<<"Parameterized constructor in derived class "<<y<<endl;
        };
        
        // to access the parameterized constructor of base class
        Derived ( int x, int y ) : Base( x ) {
            cout<<"Parameterized constructor of derived class "<<y<<endl;
        };
};