// program to find the pair of numbers whose sum = k
// sorted

#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of the array"<<endl;
    cin>>n;

    cout<<"Enter "<<n<<" numbers"<<endl;
    int A[n];
    for(int i=0; i<n; i++){
        cin>>A[i];
    };

    int k;
    cout<<"Enter the value of k"<<endl;
    cin>>k;

    int i=0;
    int j=n-1;
    while( i < j ){
        if(A[i] + A[j] == k){
            cout<<A[i]<<" + "<<A[j]<<" = "<<k<<endl;
            i++;
            j--; 
        } else if( A[i] + A[j] > k ){
            j--;
        } else{
            i++;
        }
    }

}