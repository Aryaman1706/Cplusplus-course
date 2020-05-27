// program to demonstrate lower triangular matrix
/*
1 0 0 0
2 3 0 0
4 5 6 0
7 8 9 10

Elements are present when row>=column

Number of non zero elements
1 + 2 + 3 + 4 ... n = n(n+1) / 2

Row major
\ 1 \ 2 3 \ 4 5 6 \ 7 8 9 10

Skip i rows and then skip j elemnts
M[i][j] = ( 1 + 2 + 3 ...+ i ) +  j
M[i][j] = i(i+1)/2 + j

Column major
\ 1 2 4 7 \ 3 5 8 \ 6 9 \ 10 \
M[i][j] = (n + n-1 + n-2 +...+(n-(j-1)) + i - j
M[i][j] = ( n(j-1) - ((j*(j-1))/2) + i - j
*/

#include<iostream>
using namespace std;
class LowTriMatrix{
    private:
        int size;
        int *A;
    public:
        LowTriMatrix(int n){
            size = n;
            A = new int[size];
        };
        void setRow (int i, int j, int x){
            static int index;
            if(i >= j){
                index = (i*(i+1))/2 + j;
                A[index] = x;
            }
        };
        void displayRow(){
            static int index;
            for(int i=0; i<size; i++){
                for(int j=0; j<size; j++){
                    if( i >= j ){
                        index = (i*(i+1)/2) + j; 
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
            if(i >= j){
                index = size*(j-1) - ( (j*(j-1))/2 ) + i - j;
                A[index] = x;
            }
        };
        void displayCol(){
            static int index;
            for(int i=0; i<size; i++){
                for(int j=0; j<size; j++){
                    if( i >= j ){
                        index = size*(j-1) - ( (j*(j-1))/2 ) + i - j;
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
    LowTriMatrix M(n);
    int x;
    cout<<"Enter the elements"<<endl;
    for(int i =0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<"( "<<i<<" , "<<j<<" )"<<endl;
            cin>>x;
            M.setCol(i, j, x);
        }
    };
    M.displayCol();    
}