#include <iostream>
#include "Complex.h"
using namespace std;


Complex::Complex(){
	real=0;
	image=0;
}

Complex::Complex(int a,int b){
	real=a;
	image=b;
}

Complex::Complex(const Complex &a){
	real=a.real;
	image=a.image;
}

Complex::~Complex(){
	//delete real;
	//delete image;
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


Complex Complex::add(Complex a){
        Complex temp;
        temp.assignReal(real+a.real);
	temp.assignImage(image+a.image);
	return (temp);
}

Complex Complex::subtract(Complex a){
        Complex temp;
        temp.assignReal(real-a.real);
	temp.assignImage(image-a.image);
    	return (temp);
}

Complex Complex::multiply(Complex a){
	Complex temp;
        temp.assign(real,image);
        temp.assignReal(a.real*real-a.image*image);
	temp.assignImage(a.image*real+image*a.real);
        return temp;
}
Complex Complex::division(Complex a){
	Complex temp;
        temp.assign(real,image);

	temp.assignReal((image*a.image+a.real*real)/(a.image*a.image+a.real*a.real));	
	temp.assignImage((image*a.real-a.image*real)/(a.image*a.image+a.real*a.real));
	return temp;
}

