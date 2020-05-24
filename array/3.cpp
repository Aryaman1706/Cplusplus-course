// program to find duplicates in an array

#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of the array"<<endl;
    cin>>n;

    int A[n];
    cout<<"Enter "<<n<<" elements"<<endl;
    for(int i=0; i<n; i++){
        cin>>A[i];
    };

    int max = A[0];
    int min = A[0];
    for(int i=0; i<n; i++){
        if(A[i] < min){
            min = A[i];
        } else if( A[i] > max ){
            max = A[i];
        }
    };

    int H[max+1] = {0};
    for(int i=0; i<n; i++){
        H[A[i]]++;
    };

    int i;
    for(i=min; i<=max; i++){
        if( H[i] > 1 ){
            cout<<i<<" is a duplicate"<<endl;
            cout<<i<<" occurs "<<H[i]<<" times"<<endl; 
        };
    };
    
}