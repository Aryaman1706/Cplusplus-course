// program to implement function overriding

#include<iostream>
using namespace std;

// base class
class Base {
    public:
        void funct(){
            cout<<"hello i am base class"<<endl;
        };
};

// derived class
class Derived : public Base {
    public:
        void funct(){
            cout<<"hello i am derived class"<<endl;
        }
};

int main(){
    Base b;
    b.funct();
    cout<<endl;
    Derived d;
    d.funct(); // function of derived class was called ie funct is overrided by funct in derived class
}