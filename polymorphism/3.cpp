// program to demonstrate runtime polymorphism ( pure virtual functions )

#include<iostream>
using namespace std;

// class car // class is virtual // Abstract class // this class has the functions that must be overrided 
// you can not have object but you can have pointers to achieve polymorphism // main fuction of class is polymorphism
class Car {
    public:
        virtual void start() = 0; // pure virtual functions // these must be overrided
        virtual void honk() = 0; // pure virtual functions 
};

// class bmw
class BMW : public Car {
    public:
        void start(){
            cout<<"BMW starting..."<<endl;
        };
        void honk(){
            cout<<"horn BMW"<<endl;
        };
};

// class ford
class Ford : public Car{
    public:
        void start(){
            cout<<"Ford starting..."<<endl;
        };
        void honk(){
            cout<<"horn Ford"<<endl;
        };
};

int main(){
    Car* ptr = new BMW();
    ptr->start();
    ptr->honk();
    ptr = new Ford();
    ptr->start();
    ptr->honk();
}