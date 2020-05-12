// program to add two complex numbers using friend function
#include<iostream>
using namespace std;

class Complex{
    private:
        int real,img;
    public:
        Complex ( int r = 0, int i = 0 ){
            real = r;
            img = i;
        };

        void display(){
            cout<<real<<"+"<<img<<"i";
        };
        
        friend Complex operator+ ( Complex c1, Complex c2 );
};

Complex operator+ ( Complex c1, Complex c2 ) {
    Complex temp;
    temp.real = c1.real + c2.real;
    temp.img = c1.img + c2.img;
    return temp;
};

int main () {
    Complex c1 (1,1), c2 (7,9), c3;
    c3 = c1+c2;
    c3.display();
}