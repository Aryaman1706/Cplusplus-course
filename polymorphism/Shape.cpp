// program is the solution to student assignment

#include<iostream>
using namespace std;

// class shape // abstract
class Shape {
    public:
        virtual float area() = 0;
        virtual float perimeter() = 0;
};

// class rectangle
class Rectangle : public Shape {
    private:
        int length,breadth;
    public:
        Rectangle( int l=0, int b=0 ) {
            length = l;
            breadth = b;
        };
        float perimeter(){
            return ( 2*( length + breadth ) );
        };
        float area(){
            return ( length*breadth );
        };
};

// class circle
class Circle : public Shape {
    private:
        int radius;
    public:
        Circle( int r=0 ) {
            radius = r;
        };
        float perimeter(){
            return ( 2 * 3.14 * radius );
        };
        float area(){
            return ( 3.14 * radius * radius );
        };
};

int main(){
    Shape* ptr;
    ptr = new Rectangle( 10, 20 );
    cout<<"Perimeter of Rectangle "<<ptr->perimeter()<<endl;
    cout<<"Area of Rectangle "<<ptr->area()<<endl;
    ptr = new Circle( 100 );
    cout<<"Perimeter of Circle "<<ptr->perimeter()<<endl;
    cout<<"Area of Circle "<<ptr->area()<<endl;

}