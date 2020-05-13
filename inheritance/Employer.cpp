// program is the solution to student assignment

#include<iostream>
using namespace std;

// employee class
class Employee {
    private:
        string id,name;
    public:
        Employee ( string x, string y ) {
            id = x;
            name = y;
        };
        string getId(){
            return id;
        };
        string getName(){
            return name;
        };
};

// Full time employee
class FullTimeEmployee : public Employee {
    private:
        long long int salary;
    public:
        FullTimeEmployee( string x, string y, long long int sal ) : Employee ( x, y ) {
            salary = sal;
        };
        long long int getSalary () {
            return salary;
        };
};

// Part time employee
class PartTimeEmployee : public Employee {
    private:
        int wage;
    public:
        PartTimeEmployee( string x, string y, int w ) : Employee( x, y ) {
            wage = w;
        };
        int getWage(){
            return wage;
        };
};

int main(){
    FullTimeEmployee fte ( "5r1", "Tony", 500000 );
    PartTimeEmployee pte ( "6t2", "Bruce", 500 );
    cout<<"Full Time Employee"<<endl;
    cout<<fte.getId()<<" "<<fte.getName()<<" "<<fte.getSalary()<<endl;
    cout<<endl;
    cout<<"Part Time Employee"<<endl;
    cout<<pte.getId()<<" "<<pte.getName()<<" "<<pte.getWage()<<endl;
};