/* 0000 IMPORTANT 0000 */
// program to solve TOWER OF HANOI using recursion

#include<iostream>
using namespace std;

void TOH (int n, char A, char B, char C){
    // base case
    if(n <= 0){
        return;
    };
    // recursive case
    TOH(n-1, A, C ,B); // transfer n-1 disks form A to B using C for me
    cout<<"moving disk from "<<A<<" to "<<C<<endl; // then i will transfer 1 disk from A to C using B
    TOH(n-1, B, A ,C); // transfer n-1 disks from B to C using A for me
}

int main(){
    int n;
    cin>>n;
    TOH(n, 'A', 'B', 'C');
}