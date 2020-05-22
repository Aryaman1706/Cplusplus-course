/*0000 IMPORTANT 0000*/
// program to find the nth fibonacci term using recursion
// program to demonstrate memoization

// 0 1 1 2 3 5 8 13 21 34 55 89 ....

#include<iostream>
using namespace std;

int arr[100]; // to help in memoization

// using recursion (1st, easy)
int fib1(int i){
    // base condition
    if( i<=1 ){
        return i;
    }
    // recursive case
    return ( fib1(i-2) + fib1(i-1) );
    /* Time complexity = O(2^n) */
};

// using iteration
int fib2(int i){
    int a = 0, b = 1, c;
    if( i<=1 ){
        return i;
    };
    for(int j = 2; j <= i ; j++){
        c = a + b;
        a = b;
        b = c;
    }
    return c;
    /* Time complexity = O(n) */
};

// using recursion ( memoization )
int fib3( int i ){
    // base case
    if(i<=1){
        arr[i] = i;
        return i;
    };
    // recursive case
    if(arr[ i-2 ] == -1){
        arr[ i-2 ] = fib3(i-2 );
    };
    if( arr[i-1] == -1 ){
        arr[ i-1 ] = fib3(i-1 );
    };
    arr[i] = arr[i-2] + arr[i-1];

    return ( arr[ i-2 ] + arr [ i-1 ] ) ;
    /* Time complexity = O(n) */
};

int main(){
    int n;
    cout<<"Enter the value of n :-"<<endl;
    cin>>n;

    for(int j =0 ; j<100 ; j++ ){
        arr[j] = -1;
    };

    cout<<"fib1()"<<endl;
    cout<<fib1(n)<<endl;

    cout<<"fib2()"<<endl;
    cout<<fib2(n)<<endl;

    cout<<"fib3()"<<endl;
    cout<<fib3(n);
}