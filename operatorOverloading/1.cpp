// program to add two complex numbers
#include<iostream>
using namespace std;

class Complex {
	private:
		int real,img;
	
	public:
	Complex( int r=0, int i = 0 ) {
		real = r;
		img = i;
	};

	Complex operator+ ( Complex x ) {
		Complex temp;
		temp.real = real + x.real;
		temp.img = img + x.img;
		return temp;
	};

	void display () {
		cout<< real <<"+"<<"i"<<img;
	};
};


int main(){
	Complex c1(2,5), c2(5,2), c3;
	c3 = c1 + c2;
	c3.display();
};