// program to demonstrate static data members and static function

#include<iostream>
using namespace std;

class Student {
    private:
        int rollNo;
        string name;
    
    public:
        static int count; // static data member, single memory is allocated.
        Student ( string s ) {
            name = s;
            count++;
            rollNo = count;
        };
        void display(){
            cout<<name<<"   "<<rollNo<<endl;
        };
        static void getvaluesS(){
            cout<<count;
            //cout<<name; // static member functions can only access static data members
        };
        void getvalues(){
            cout<<count; // member functions can access static members
            cout<<name; 
        };


};

int Student::count = 0;

int main(){
    Student s1("Elon");
    Student s2("Musk");
    s1.display();
    s2.display();
    cout<<"count"<<" "<<s1.count<<" "<<s2.count<<" "<<Student::count<<endl; // static members can be accessed via both object and class
}