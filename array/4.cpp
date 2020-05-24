// program to find the pair of numbers whose sum = k

#include<iostream>
using namespace std;
int main(){
    int size;
    cout<<"Enter the size of the array"<<endl;
    cin>>size;
    
    cout<<"Enter "<<size<<" numbers"<<endl;
    int A[size];
    for(int i=0; i<size; i++){
        cin>>A[i];
    };

    cout<<"Enter the total sum"<<endl;
    int k;
    cin>>k;

    int max=A[0];
    int min=A[0];
    for(int i=0; i<size; i++){
        if(A[i]>max){
            max = A[i];
        } else if( A[i] < min){
            min = A[i];
        }
    };

    int H[max+1] = {0};
    for(int i=0; i<size; i++){
        H[A[i]]++;
        if(H[ k - A[i] ] != 0){
            cout<<A[i]<<" + "<<k-A[i]<<" = "<<k<<endl;
        }
    };
}