// Revise
// program to overlaod "<<" such that it displays complex number
// program to overlaod ">>" such that it inputs complex number

#include<iostream>
using namespace std;
class Complex {
    private:
        
        int real,img;
    
    public:

        Complex( int r=0, int i=0 ) {
            real = r;
            img = i;
        };

        // to display
        friend ostream& /*i want to use cout again in the same line*/  operator<< ( ostream &out /*as it takes cout*/ , Complex &c /*complex number*/ );

        // to input
        friend istream& operator>> ( istream &in, Complex &c );
};

// to display
ostream& operator<< ( ostream &out, Complex &c ) {
    out/*when cout is passed it becomes o*/<<c.real<<"+i"<<c.img<<endl;
    return out; /*i have to return cout (o) so that it could be used further*/
};

// to input
istream& operator>> ( istream &in, Complex &c ) {
    in>>c.real>>c.img;
    return in;
};

int main(){
    Complex c1, c2;
    cin>>c1>>c2;
    cout<<c1<<c2;    
}