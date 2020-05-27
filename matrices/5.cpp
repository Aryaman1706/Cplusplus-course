// progrma to demonstrate toeplitz matrix
/*
1 2 3 4
5 1 2 3
6 5 1 2
7 6 5 1

Number across the diagonals are eqaul
No of elements to be stored in 1D array = n + n-1 ( 0th row and 0th column except 0,0 element )

\ 1 2 3 4 \ 5 6 7 \
M[i][j]=>
case 1) (upper triangular) if (i<=j) => index = j-i
case 2) (lower triangular) if(i>j) => index = n + i-j-1
*/

#include<iostream>
using namespace std;

class Toeplitz{
    private:
        int size;
        int *A;
    public:
        Toeplitz(int n){
            size = n;
            A = new int[n];
        };
        void set(int i, int j, int x){
            static int index;
            if( i <= j ){
                index = j-i;
                A[index] = x;
            } else{
                index = size + i-j-1;
                A[index] = x;
            }
        };
        void display () {
            static int index;
            for(int i=0; i<size; i++){
                for(int j=0; j<size; j++){
                    if(i<=j){
                        index = j-i;
                        cout<<A[index]<<"   ";
                    }else{
                        index = size + i-j-1;
                        cout<<A[index]<<"   ";
                    }
                }
                cout<<endl;
            }
        }
};

int main(){
  int n;
    cout<<"Enter the dimension of matrix"<<endl;
    cin>>n;
    Toeplitz M(n);
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