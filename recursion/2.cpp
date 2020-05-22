// program to find sum of n natural numbers using recursion

// this is the example of tail recursion why?? because the work is done before and recursive function is called after that
#include<iostream>
using namespace std;

int globalCount = 0;

int sum(int i){
    static int staticCount = 0;
    // base condition
    if(i<=0){
        // return globalCount;
                /*OR*/
        return staticCount;
    };
    // recursive case
    // globalCount = globalCount + i;
            /*OR*/
    staticCount = staticCount + i;
    cout<<"count "<<staticCount<<endl;
    sum(i-1);
}

int main(){
    int n;
    cout<<"Enter the number till which sum is to be calculated :-"<<endl;
    cin>>n;
    cout<< sum(n);
    return 0;
}