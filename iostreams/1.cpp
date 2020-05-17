// program to demonstrate writing file

#include<iostream>
#include<fstream>
using namespace std;
int main(){
    ofstream ofs ("WriteFile.txt", ios::trunc ); // two ways --> 1) ios::trunc which clears previos content and add new content 2) ios::app which appends the new data ios::trunc is default
    ofs<<"Aryaman"<<endl;
    ofs<<10<<endl;
    ofs<<"G"<<endl;

    ofs.close();
}