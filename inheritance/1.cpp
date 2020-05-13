// program to show inheritance via rectangle and cuboid classes

#include<iostream>
using namespace std;

// Rectangle class
class Rectangle {
    private:
        int length,breadth;
    public:
        void setLength( int l ){
            length = l;
        };
        int getLength(){
            return length;
        };
        void setBreadth( int b ){
            breadth = b;
        };
        int getBreadth(){
            return breadth;
        };
        int area(){
            return length*breadth;
        };
        int perimeter(){    
            return 2*( length + breadth );
        };
};

//Cuboid class
class Cuboid : public Rectangle {
    private:
        int height;
    public:
        Cuboid ( int l = 0, int b = 0, int h = 0 ){
            setLength(l);
            setBreadth(b);
            height = h;
        };
        void setHeight( int h ){
            height = h;
        };
        int getHeight(){
            return height;
        };
        int volume(){
            int vol = 0;
            vol = getLength() * getBreadth() * height;
            return vol;
        };
};

int main(){
    Cuboid a ( 10, 5, 6 );
    cout<<"Length of cuboid is : "<<a.getLength()<<endl;
    cout<<"Breadth of cuboid is : "<<a.getBreadth()<<endl;
    cout<<"Height of cuboid is : "<<a.getHeight()<<endl;
    cout << endl;
    cout<<"Perimeter of rectangle is : "<<a.perimeter()<<endl;
    cout<<"Area of rectangle is : "<<a.area()<<endl;
    cout<<"Volume of cuboid is : "<<a.volume()<<endl;
}