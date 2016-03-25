//Complex.h
#ifndef COMPLEX_H
#define COMPLEX_H
// Write class definition for Complex
class Complex{
     public:
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
