// program to demonstrate upper triangular matrix
/*
0 | 1 2 3 4
1 | 0 5 6 7
2 | 0 0 8 9
3 | 0 0 0 10

Elements are present where column >= row

// Row major
\ 1 2 3 4 \ 5 6 7 \ 8 9 \ 10
M[i][j] = (n + n-1 + n-2 ..+ n-(i-1)) + j - i
M[i][j] = n(i) - ((i*(i-1))/2) + j - i

// Column Major
\ 1 \ 2 5 \ 3 6 8 \ 4 7 9 10
M[i][j] = ( 1 + 2 + 3 + ...+j ) + i 
M[i][j] = (j*(j+1))/2 + i

*/

#include<iostream>
using namespace std;
class UpperTriMatrix{
    private:
        int size;
        int *A;
    public:
        UpperTriMatrix(int n){
            size = n;
            A = new int[size];
        };
        void setRow (int i, int j, int x){
            static int index;
            if(j >= i){
                index = size*i - ((i*(i-1))/2) + j - i;
                A[index] = x;
            }
        };
        void displayRow(){
            static int index;
            for(int i=0; i<size; i++){
                for(int j=0; j<size; j++){
                    if( j >= i ){
                        index = size*i - ((i*(i-1))/2) + j - i;
                        cout<<A[index]<<"   ";
                    }else{
                        cout<<0<<"   ";
                    }
                }
                cout<<endl;
            }
        };
        void setCol (int i, int j, int x){
            static int index;
            if(j >= i){
                index = ((j*(j+1))/2) + i;
                A[index] = x;
            }
        };
        void displayCol(){
            static int index;
            for(int i=0; i<size; i++){
                for(int j=0; j<size; j++){
                    if( j >= i ){
                        index = ((j*(j+1))/2) + i;
                        cout<<A[index]<<"   ";
                    }else{
                        cout<<0<<"   ";
                    }
                }
                cout<<endl;
            }
        };
};
int main(){
    int n;
    cout<<"Enter the dimension of matrix"<<endl;
    cin>>n;
    UpperTriMatrix M(n);
    int x;
    cout<<"Enter the elements"<<endl;
    for(int i =0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<"( "<<i<<" , "<<j<<" )"<<endl;
            cin>>x;
            M.setRow(i, j, x);
        }
    };
    M.displayRow();    
}
/*
Symetric matrix

2 2 2 2
2 3 3 3
2 3 4 4
2 3 4 5

No. of different element = n
Lower triangular matrix = Upper triangular matrix
*/