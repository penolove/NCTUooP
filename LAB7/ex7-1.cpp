// ex7-1.cpp
#include <iostream>
using std::cout;
using std::endl;
#include "Complex.h"



void printMeg(Complex a ,Complex b,char c){
    a.printComplex();
    cout<<c;
    b.printComplex();
    //Complex temp;
    //temp=a+b;
    cout<<"=";
    //temp.printComplex();
    //cout<<"\n";
}


int main()
{
     
    Complex a(1.0, 7.0), b(9.0, 2.0), c; // create three Complex objects
    printMeg(a, b, '+'); // output (1.0, 7.0) + (9.0, 2.0) =
    c = a + b; // invoke operator + and assign to object c
    cout << c << endl; // output object c
    printMeg(a, b, '-');// output (1.0, 7.0) - (9.0, 2.0) =
    c = a - b; // invoke operator - function and assign to object c
    cout << c << endl; // output object c
    printMeg(a, b,'*');//output (1.0, 7.0) * (9.0, 2.0) =
    c = a * b; // invoke operator * function and assign to object c
    cout << c << endl; // output object c
    printMeg(a, b, '/'); // output (1.0, 7.0) / (9.0, 2.0) =
    c = a / b; // invoke operator / function and assign to object c
    cout << c << endl; // output object c
    a.assign(10.0, 1.0); // reset object a
    b = -a;
    printMeg(a, b,'-');
    c = a - b; // invoke operator - function and assign to object c
    cout << c << endl; // output object c
    
    return 0;
    //}
}
