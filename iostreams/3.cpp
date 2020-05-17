// program to demonstrate serialization

#include<iostream>
#include<fstream>
using namespace std;

class Student {
    private:
        string name;
        int rollno;
        string branch;
    public:
        Student () {};
        Student( string s, int r, string b ){
            name = s;
            rollno = r;
            branch = b; 
        };
        friend ifstream & operator>> ( ifstream &i, Student &s );
        friend ofstream & operator<< ( ofstream &o, Student &s );
        friend ostream & operator<< ( ostream &out, Student &s );

};

ifstream & operator>> ( ifstream &i, Student &s ){
    i>>s.name;
    i>>s.rollno;
    i>>s.branch;
    return i;
};

ofstream & operator<< ( ofstream &o, Student &s ){
    o<<s.name<<endl;
    o<<s.rollno<<endl;
    o<<s.branch<<endl;
    return o;
};

ostream & operator<< ( ostream &out, Student &s ){
    cout<<s.name<<" "<<s.rollno<<" "<<s.branch<<endl;
    return out;
};


int main(){
    Student s1;
    Student s2;

    ifstream ifs;
    ifs.open("StudentRead.txt");

    ofstream ofs ("StudentWrite.txt");

    ifs>>s1;
    ifs>>s2;

    cout<<s1<<endl<<s2;

    ofs<<s1;
    ofs<<s2;

    ifs.close();
    ofs.close();

}