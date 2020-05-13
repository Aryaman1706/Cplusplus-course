// program to demonstrate base class pointer to derived class object

#include<iostream>
using namespace std;

// base class
class Man {
    public:
        void breath(){
            cout<<"Inhale... exhale... inhale... exhale..."<<endl;
        };
};

// child class
class IronMan : public Man {
    public:
        void fly(){
            cout<<"woohshh.. I am flying..."<<endl;
        };
};

int main(){
    IronMan temp;
    temp.breath();
    temp.fly();

    cout<<"Using pointers..."<<endl;

    IronMan x;
    Man *ptr = &x; // its like saying hey ironman you are a man which is correct

    /*
        Man y;
        IronMan *ptr2 = &y; // its like saying hey man you are ironman which is incorrect
    */

   ptr->breath();
    /*
        ptr->fly(); // since pointer is of Man so it can not access fly(). Its like commanding a "Man" to fly. As currently for us "IronMan" is just "Man"
    */
}