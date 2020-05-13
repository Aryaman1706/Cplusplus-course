// program to demonstrate inner class

#include<iostream>
using namespace std;

class Outer {
    int x=10;
public:
    void funct(){ // 1st member of outer class
        cout<<"hey!! i am function funct.."<<endl;
        i.display();
    };

    class Inner {
        public:
            void display(){
                cout<<"Display in inner class"<<endl;
            };
            void funct2( Outer* o ){
                cout<<"i am private in outer "<< o->x; //inner classes can access private members
            };
    };

    Inner i; // 2nd member of outer class
};

int main(){
    Outer o;
    o.funct();
    //o.display(); // since display is not member of outer

    Outer::Inner l; // l is object of inner //it cannot be declared if Inner class is private
    l.display(); // it can access display function as it is object of inner
    l.funct2(&o);
}