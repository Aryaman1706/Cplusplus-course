// program to add two rational numbers overload +, <<
// part of the student assignment

#include<iostream>
using namespace std;

class RationalNo {
    private:
        int num,den;
    
    public:
        RationalNo ( int p = 0, int q = 1 ) {
            num = p;
            den = q;
        };

        RationalNo operator+ ( RationalNo x ) {
            int denCopy = den;
            
            num = num * x.den;
            den = den * x.den;

            x.num = x.num * denCopy;
            x.den = x.den * denCopy;

            RationalNo temp;
            temp.num = num + x.num;
            temp.den = den;
            return temp;
        };
        
        // to display
        friend ostream& operator<< ( ostream &out, RationalNo &x );
};

// to display
ostream& operator<< (ostream &out, RationalNo &x){
    out<<x.num<<"/"<<x.den<<endl;
    return out;
};

int main(){
    RationalNo a ( 1, 2 ), b ( 1, 3 ), c ;
    c = a + b;
    cout<<c;
}
