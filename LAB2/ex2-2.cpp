#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <sstream>
#include <stdio.h>
#include "ex2-2.h"
using namespace std;

inline double division_real(Cplex a ,Cplex b ){
	return (a.image*b.image+b.real*a.real)/(b.image*b.image+b.real*b.real);	

}

inline double division_image(Cplex a ,Cplex b ){
        return (a.image*b.real-b.image*a.real)/(b.image*b.image+b.real*b.real);

}


inline Cplex cplex_add(Cplex a,Cplex b){
	Cplex temp;
	temp.real=a.real+b.real;
	temp.image=a.image+b.image;
	return temp;
}

inline Cplex cplex_minus(Cplex a,Cplex b){
	Cplex temp;
	temp.real=a.real-b.real;
	temp.image=a.image-b.image;
	return temp;
}

inline Cplex cplex_multi(Cplex a,Cplex b){
	Cplex temp;
	temp.real=a.real*b.real-a.image*b.image;
	temp.image=a.image*b.real+b.image*a.real;
	return temp;
}
inline Cplex cplex_division(Cplex a,Cplex b){
	Cplex temp;
	temp.real=division_real(a,b);
	temp.image=division_image(a,b);
	return temp;
}

Cplex complexOperation(Cplex a,Cplex b,char x){
	switch(x){
		case '+':
			return cplex_add(a,b);
		case '-':
			return cplex_minus(a,b);
		case '*':
			return cplex_multi(a,b);
		case '/':
			return cplex_division(a,b);
	}
}

void printComplex(Cplex *a){
	for (int i=0;i<4;i++){
						//why *(a+i).image
						//     a[i].image
		printf("%.3lf",a[i].real);
		if((a+i)->image>0){
			printf("+");
		}
		printf("%.3lf",(a+i)->image);
		printf("i\n");

	}
}


