// program to implement virtual function ( runtime polymorphism )
// used when we want to access to overrided function

#include<iostream>
using namespace std;

// base class
class Base {
    public:
       virtual void funct1(){
            cout<<"hello i am funct1 in base class"<<endl;
        };
        void funct2(){
            cout<<"hello i am funct2 in base class"<<endl;
        };
};

// derived class
class Derived : public Base {
    public:
        void funct1(){
            cout<<"hello i am funct1 in derived class"<<endl;
        };
        void funct2(){
            cout<<"hello i am funct2 in derived class"<<endl;
        };
};

int main(){
    cout<<"Derived class object"<<endl;
    Derived d1;
    d1.funct1();
    d1.funct2();
    cout<<"Base class object"<<endl;
    Base b1;
    b1.funct1();
    b1.funct2();
    cout<<"pointer of base class to derived class object"<<endl;
    Derived d2;
    Base* ptr = &d2;
    ptr->funct1(); // overriden funct1 is displayed as it was virtual
    ptr->funct2();
}