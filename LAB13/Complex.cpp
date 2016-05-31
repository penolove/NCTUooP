#include <iostream>
#include "Complex.h"
using namespace std;


ostream& operator<<(ostream& out, const Complex& complex) {
     
      out << "(" << complex.real << " + " << complex.image<<"i)";

      return out;
}

Complex::Complex(){
	real=0;
	image=0;
}

Complex::Complex(int a,int b){
	real=a;
	image=b;
}



void Complex::assign(double a,double b){
     real=a;
     image=b;
}
void Complex::printComplex(){
     cout<<"("<<real<<","<<image<<")";
}

void Complex::assignReal(double a){
     real=a;
}
void Complex::assignImage(double a){
     image=a;
}



int Complex::operator <( Complex a) const{
    	return (real<a.real);
}




