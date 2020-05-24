// program to find missing number in an array
// 2 4 6 3 7 8

#include<iostream>
using namespace std;
int main(){
    int size;
    cout<<"Enter the size of the array"<<endl;
    cin>>size;

    int A[size];

    cout<<"Enter the elements"<<endl;
    for(int i=0; i<size; i++){
        cin>>A[i];
    };

    int max = A[0];
    int min = A[0];
    
    for(int i=0; i<size; i++){
        if( A[i] > max ){
            max = A[i];
        } else if ( A[i] < min ){
            min = A[i];
        };
    };

    int H[max] = {0};

    for(int i=0; i<size; i++){
        H[A[i]]++;
    };

    for(int i=min; i<max; i++){
        if(H[i] == 0){
            cout<<i<<" is missing"<<endl;
        }
    };
    
}