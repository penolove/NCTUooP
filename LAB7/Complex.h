//Complex.h
#ifndef COMPLEX_H
#define COMPLEX_H
// Write class definition for Complex
using namespace std ;
class Complex{
     public:
	 Complex();
	 ~Complex();
	 Complex(int a,int b);
	 Complex(const Complex &a);
         void assign(double a,double b);
         void printComplex();
         friend void printMeg(Complex ,Complex  ,char );
         friend ostream& operator <<(ostream&,const Complex &); 
         Complex operator +(Complex a);
         Complex operator *(Complex a);
         Complex operator -(Complex a);
         Complex operator -();
         Complex operator /(Complex a);
         void assignReal(double a);
         void assignImage(double a);

     private:
         double real;
         double image;
};


#endif
