// program to demonstrate ways of inheritance

// Conclusion-->
/*
    NOTE :- we can not access private members of parent class in child class
     
    Becomes:-
    publicaly inherit ==> public -> public, protected -> protected
    protected inherit ==> public -> protected, protected -> protected
    privately inherit ==> public -> private, protected -> private
*/

#include<iostream>
using namespace std;

// parent class
class Parent {
    private: int a;
    protected: int b;
    public:
        int c;
        void functParent(){
            a=10,b=20,c=30;
        };
};
// child class
class Child : public Parent {
    public:
        void functChild(){
            //a=1; // reason-> a is private
            b=2; // b remains protected
            c=3; // c remains public
        };
};

// grandchild class
class GrandChild : public Child {
    public:
        void functGrandChild() {
            //a=5; // reason-> a is private
            b=10; 
            c=15;
        };
};

int main(){
    Child x;
    //x.a = 7; // reason-> a is private
    //x.b = 8; // reason-> b is protected
    x.c = 9; 
}
