// program to demonstrate multiple try and catch

#include<iostream>
using namespace std;
int main(){
   int a, b, c, d;
   cin>>a>>b>>c>>d;
   try{
       if ( a == 0 ) {
           throw 1;
       } else if ( b == 0 ) {
           throw 1.5f;
       } else if ( c == 0 ) {
           throw "error...";
       } else if ( d == 0 ) {
           throw 'e';
       };
   } 
   catch ( int i ){
       cout<<"catch int"<<endl;
   }
   catch ( float f ) {
       cout<<"catch float"<<endl;
   }
   catch(...){ // it catches all that are not caught till now // it should be at the end
       cout<<"catch all"<<endl;
   }
    cout<<"End..."<<endl;
}