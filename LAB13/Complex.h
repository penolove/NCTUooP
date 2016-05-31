//Complex.h
#ifndef COMPLEX_H
#define COMPLEX_H
// Write class definition for Complex
using namespace std ;
class Complex{
     public:
	 Complex();

	 Complex(int a,int b);

         void assign(double a,double b);
         void printComplex();
         friend void printMeg(Complex ,Complex  ,char );
         friend ostream& operator <<(ostream&,const Complex &); 
	 int operator <( Complex a) const;

         void assignReal(double a);
         void assignImage(double a);

     private:
         double real;
         double image;
};


#endif
