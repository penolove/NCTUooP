//Complex.h
#ifndef COMPLEX_H
#define COMPLEX_H
// Write class definition for Complex
class Complex{
     public:
	 Complex();
	 ~Complex();
	 Complex(int a,int b);
	 Complex(const Complex &a);
         void assign(double a,double b);
         void printComplex();
         Complex add(Complex a);
         Complex multiply(Complex a);
         Complex subtract(Complex a);
         Complex division(Complex a);
         void assignReal(double a);
         void assignImage(double a);

     private:
         double real;
         double image;
};


#endif
