// program to demonstrate accessability of data members of a class ( Base )

// Conclusion-->
/*
    Accessable in :-
    public -> base class, derived class and object
    private -> base class
    protected -> base class and derived class
*/

#include<iostream>
using namespace std;

class Base {
    private:
        int a;
    public:
        int b;
        
        void functBase(){
            a=10;
            b=20;
            c=30;
        };
    protected:
        int c;
};

class Derived : Base {
    public:
        void functDerived(){
            //a=1; // Reason-> a is private and cannot be accessed in derived class
            b=2;
            c=3;
        }
};

int main(){
    Base d;
    //d.a = 5; // Reason-> private
    d.b = 6;
    // d.c = 7; // Reason-> protected
}