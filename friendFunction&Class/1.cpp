// program to demonstrate frined class

#include<iostream>
using namespace std;

class Class2; // class need to be defined first otherwise there would be an error

class Class1 {
    private:
        int a;
    friend Class2;
};

class Class2 {
    public:
        Class1 x;
        void funct() {
            x.a = 10;
        };
        void display(){
            cout<<x.a<<endl;
        };
};

int main(){
    Class2 c;
    c.funct();
    c.display();
}
