// program to demonstrate operations on array

#include<iostream>
using namespace std;
int mid;
class Array{
    private:
        int size, length;
        int *A;
    public:
        Array( int s, int l){
            size = s;
            length = l;
            A = new int [size];
        };
        void display(){
            cout<<"Hey!! This is your array "<<endl;
            for(int i=0; i<length; i++){
                cout<<A[i]<<" ";
            }
            cout<<endl;
        };
        void fill(){
            cout<<"Enter the numbers "<<endl;
            for(int i=0; i<length; i++){
                cin>>A[i];
            };
        };
        void Delete() {
            int index;
            cout<<"Enter the index you want to delete "<<endl;
            cin>>index;
            for(int i = index; i<length-1; i++){
                A[i] = A[i+1];
            };
            length--;
        };
        void Insert(){
            int index, num;
            cout<<"Enter the index at which you want to insert"<<endl;
            cin>>index;
            cout<<"Enter the no to insert"<<endl;
            cin>>num;

            for(int i = length ; i > index; i--){
                A[i] = A[i-1];
            };
            A[index] = num;
            length++;
        };
        void linearSearch(){
            int key;
            cout<<"Enter the number you want to find"<<endl;
            cin>>key;
            for(int i=0; i<length; i++){
                if(A[i] == key){
                    cout<<key<<" found at "<<i<<endl;
                    return;
                }
                
            };
            cout<<key<<" not found :<"<<endl;
        };
        void binarySearch(){
            // condition :- Array should be sorted
            int key;
            cout<<"Enter the number you want to find"<<endl;
            cin>>key;

            int start =0, end = length-1, mid;
            while(start <= end){
                mid = (start + end)/2;
                if(key == A[mid]){
                    cout<<key<<" found at "<<mid;
                    return;
                } else if(key > mid){
                    start = mid +1;
                } else{
                    end = mid-1;
                }
            };
            cout<<key<<" not found :<"<<endl;
        };
        void R_binarySearch(int key, int start, int end){
            mid = (start + end)/2; 
            // base case
            if(end < start){
                cout<<key<<" not found"<<endl; 
                return;
            };
            if(key == A[mid]){
                cout<<key<<" found at "<<mid<<endl;
                return;
            }
            //recursive case
            else if(key > A[mid]){
                R_binarySearch(key, mid+1, end);
            } else {
                R_binarySearch(key, start, mid-1);
            };
        }
};

int main(){
    int size, length;
    cout<<"Enter the size of array "<<endl;
    cin>>size;
    
    cout<<"Enter the length of array "<<endl;
    cin>>length;

    Array A(size, length);
    
    A.fill();
    A.display();
    int key;
    cout<<"Enter the number to find"<<endl;
    cin>>key;
    A.R_binarySearch(key, 0, 4);
}