// program to demonstrate tridiagonal matrix
/*
1  9  0  0  0
13 2  8  0  0
0  12 3  7  0
0  0  11 4  6
0  0  0  10 5

No of non zero elements = 5 + 4 + 4 => n + n-1 + n-1

Elements are present where:-
1) i-j=0 ( main diagonal )
2) i-j=1 ( lower diagonal )
3) i-j=-1 ( upper diagonal )

Fill the 1D array as per diagonals.
\ 13 12 11 10 \ 1 2 3 4 5 \ 9 8 7 6 \
M[i][j]=>
case 1) if(i-j = 1) => index = j
case 2) if(i-j = 0) => index = n-1 + j
case 3) if(i-j = -1) => index = n + n-1 + i
*/
#include<iostream>
using namespace std;

class TriDiagonal{
    private:
        int size;
        int* A;
    public:
        TriDiagonal(int n){
            size = n;
            A = new int [n];
        };
        void set(int i, int j, int x){
            static int index;
            if( i-j == 0 ){
                index = size-1 + j;
                A[index] = x;
            } else if( i - j == 1 ){
                index = j;
                A[index] = x;
            } else if( i-j == -1 ){
                index = 2*size -1 + i;
                A[index] = x;
            };
        };
        void display(){
            static int index;
            for(int i=0; i<size; i++){
                for(int j=0; j<size; j++){
                    if( i-j == 0 ){
                        index = size-1 + j;
                        cout<<A[index]<<"   ";
                    } else if( i - j == 1 ){
                        index = j;
                        cout<<A[index]<<"   ";
                    } else if( i-j == -1 ){
                        index = 2*size -1 + i;
                        cout<<A[index]<<"   ";
                    }else{
                        cout<<0<<"   ";
                    };
                }
                cout<<endl;
            }
        };
};

int main(){
    int n;
    cout<<"Enter the dimension of matrix"<<endl;
    cin>>n;
    TriDiagonal M(n);
    int x;
    cout<<"Enter the elements"<<endl;
    for(int i =0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<"( "<<i<<" , "<<j<<" )"<<endl;
            cin>>x;
            M.set(i, j, x);
        }
    };
    M.display();    
}