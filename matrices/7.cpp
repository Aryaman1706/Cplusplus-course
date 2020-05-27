// program to create and add polynomials
/*
poly = 3*x^5 + 5*x^4 + 7*x^2 + 3*x + 9

Array of objects of Terms ->
coeff-> 3 5 7 3 |9|
power-> 5 4 2 1 |0| <- an object of Term

Classes
Term => coeff, power
Poly => num, array of Terms // Here num is number of non zero values
*/
#include<iostream>
using namespace std;

class Term{
    public:
        int coeff, power;
};

class Poly{
    private:
        int num;
        Term* A;
    public:
        Poly(int n){
            num = n;
            A = new Term[n]; 
        };
        friend istream& operator>> (istream &in, Poly &P);
        friend ostream& operator<< (ostream &out, Poly &P);
        Poly operator+ (Poly &P);
};

istream& operator>> (istream &in, Poly &P){
    cout<<"Enter coeff and power of non zero terms"<<endl;
    for(int i=0; i<P.num; i++){
        cout<<"coeff :-";
        in>>P.A[i].coeff;
        cout<<"power:-";
        in>>P.A[i].power;
    }
    return in;
};

ostream& operator<< (ostream &out, Poly &P){
    out<<"Polynomial is"<<endl;
    for(int i=0; i<P.num; i++){
        out<<P.A[i].coeff<<" * x^"<<P.A[i].power<<" + ";
    }
    return out;
};

Poly Poly :: operator+ ( Poly &P ){
    int i=0, j=0, k=0; // i -> given poly, j -> passed Poly, k -> result
    Poly res(num + P.num);
    while(i<num && j<P.num){    
        if(A[i].power > P.A[j].power){
            res.A[k] = A[i];
            k++;
            i++;
        } else if (A[i].power < P.A[j].power){
            res.A[k] = P.A[j];
            k++;
            j++;
        } else {
            res.A[k].power = A[i].power;
            res.A[k].coeff = A[i].coeff + P.A[j].coeff;
            k++;
            i++;
            j++;
        }
    };
    for(;i<num; i++){
        res.A[k] = A[i];
        k++;
    };
    for(;j<P.num; j++){
        res.A[k] = P.A[j];
        k++;
    };
    res.num = k;
    return res;
}

int main(){
    Poly P1(4);
    cin>>P1;
    cout<<P1;

    Poly P2(5);
    cin>>P2;
    cout<<P2;

    Poly result = P1+P2;
    cout<<result;
}