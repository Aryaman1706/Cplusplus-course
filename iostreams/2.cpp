// program to demonstrate reading files

#include<iostream>
#include<fstream>
using namespace std;
int main(){
    ifstream ifs;
    ifs.open("ReadFile.txt");

    if(!ifs){
        cout<<"No such file found-Metord 1"<<endl;
        return 0;
    };

    // if(!ifs.is_open()/*return true if file is open*/){
    //     cout<<"No such file found-Methord 2"<<endl;
    // }

    string str;
    int x;
    char y;

    ifs>>str;
    ifs>>x;
    ifs>>y;
    
    cout<<str<<" "<<x<<" "<<y<<endl;
    ifs.close();
    /*ifs.eof() is a function that returns true if we have reached the end file*/ 
}