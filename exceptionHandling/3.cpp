// program to demonstrate throwing and catching object

#include<iostream>
using namespace std;

class MyException {
    private:
        string error;
    public:
        MyException ( string s ) {
            error = s;
        };
        void display() {
            cout<<error<<endl;
        };
};

int main(){
    int a, b;
    cin>>a>>b;
    try {

        if ( a == 0 ) {
            throw MyException("a is zero...");
        }
        else if ( b == 0 ) {
            throw MyException("b is zero...");
        }
        cout<<a<<" "<<b<<endl;

    } catch ( MyException e ) {
        e.display();
    }
    cout<<"End...";
}