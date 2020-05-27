// program to add and create sparse matrix
/*
0 1 0 0
0 0 0 8
9 0 0 1
0 0 7 0

A matrix in which most of the elements are zero
We will store all the non zero elements in an structure with 3 properies
1) Row of non zero element
2) Column of non zero element
3) Value of non zero element

Array of elements ->
Row-> 0 1 2 2 |3|
Col-> 1 2 0 3 |2|
Val-> 1 8 9 1 |7| <- this is one element

*/

#include<iostream>
using namespace std;

class Element{
    public:
        int i; // row index 
        int j; // column index
        int val; // value
};

class Sparse {
    private:
        int row; // no of rows
        int col; // no of columns
        int num; // no of non zero elements
        Element *E; // pointer of type Element which will point to array of elements
    public:
        Sparse(int r, int c, int n){
            row = r;
            col = c;
            num = n;

            E = new Element[n]; 
        };
        friend istream & operator>> ( istream &in, Sparse &S ); 
        friend ostream & operator<< ( ostream &out, Sparse &S ); 
        Sparse operator+ (Sparse &S);
};

istream & operator>> ( istream &in, Sparse &S ){
    cout<<"Enter non zero elements with index"<<endl;
    for(int i=0; i<S.num; i++){
        // all these numbers would be put in element array
        cout<<"i = ";
        in>>S.E[i].i;
        cout<<"j = ";
        in>>S.E[i].j;
        cout<<"value = ";
        in>>S.E[i].val;
        cout<<endl;
    }
    return in;
};

ostream & operator<< ( ostream &out, Sparse &S ){
    int k=0; // iterator for array of Elements in Sparse
    out<<"Sparse Matrix"<<endl;
    for (int a=0; a<S.row; a++){
        for(int b=0; b<S.col; b++){
            if( S.E[k].i == a && S.E[k].j == b ){
                out<<S.E[k].val<<"   ";
                k++;
            }else {
                out<<0<<"   ";
            }
        }
        out<<endl;
    }
    return out;
};

Sparse Sparse :: operator+ (Sparse &S){
    if(row != S.row || col != S.col){
        cout<<"Can not be added as dimensions are not equal"<<endl;
        return Sparse(0,0,0);
    };
    int i=0, j=0, k=0; // i is iterator on given Sparse, j is iterator on sparse that was passed (S) and k is iterator on resultant sparse 
    Sparse res(row, col, num+S.num); // row and col of resultant would be same as the two sparse matrix and maximum possible number of non zero elements = sum of non zero elements of 2 matrix
    while(i<num && j<S.num){
        if(E[i].i < S.E[j].i){
            res.E[k] = E[i];
            k++;
            i++; 
        } else if(E[i].i > S.E[j].i){
            res.E[k] = S.E[j];
            k++;
            j++;
        } else {
            if(E[i].j < S.E[j].j){
                res.E[k] = E[i];
                i++;
                k++;
            } else if(E[i].j > S.E[j].j){
                res.E[k] = S.E[j];
                k++;
                j++;
            } else{
                res.E[k].i = E[i].i;
                res.E[k].j = E[i].j;
                res.E[k].val = E[i].val + S.E[j].val;
                i++;
                j++;
                k++;
            }
        }
    } 
    for(;i<num; i++){
        res.E[k] = E[i];
        k++;
    }
    for (; j<S.num; j++){
        res.E[k] = S.E[j];
        k++;
    }
    res.num = k;
    return res;
};

int main(){
    Sparse S1(5, 4, 7);
    cin>>S1;

    Sparse S2(5, 4, 6);
    cin>>S2;

    cout<<S1;
    cout<<endl<<"+"<<endl;
    cout<<S2;

    cout<<endl<<"="<<endl;

    Sparse sum = S1+S2;
    cout<<sum; 
}