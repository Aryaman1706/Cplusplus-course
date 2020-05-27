// program to demonstrate diagonal matrix
/*
3 0 0 0
0 2 0 0
0 0 1 0
0 0 0 7

M[i,j] = 0 if i != j
*/

// Approach :- Since most of the elements in matrix M is zero
// So we would use an alternative array which would only store the 
// Elements that are not zero that is elements along the diagonal 

#include<iostream>
using namespace std; 

class Diagonal{
    private:
        int size;
        int *A; // array for diagonal elements
    public:
        Diagonal(int n){
            size = n;
            A = new int[size];
        };
        void set(int i, int j, int x) {
            if(i == j){
                A[i] = x;
            }
        };
        int get(int i, int j){
            if( i == j ){
                return A[i];
            } else{
                return 0;
            }
        };
        void display(){
            for(int i =0; i<size; i++){
                for(int j =0; j<size; j++){
                    if(i == j){
                        cout<<A[i]<<"   ";
                    } else {
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
    Diagonal M(n);
    cout<<"Enter the elements"<<endl;
    int num;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<"( "<<i<<" , "<<j<<" )"<<endl;
            cin>>num;
            M.set(i, j, num);
        }
    };
    M.display();

}