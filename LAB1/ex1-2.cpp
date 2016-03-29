#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <sstream>
#include <stdio.h>

using namespace std;


typedef struct {

 double real;

 double image;

} Cplex;

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

inline Cplex complexOperation(Cplex a,Cplex b,char x){
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

inline void printComplex(Cplex *a){
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



int main(void){
	Cplex a;
	Cplex b;
	string temp;
	cout<<"First complex number: ";
	cin>>a.real>>a.image>>temp;
	cout<<"Second complex number: ";
	cin>>b.real>>b.image>>temp;
	cout<<"==============================\n";
	cout<<"The output results:\n";

	Cplex results[4]; 
	
	results[0] = complexOperation(a, b, '+');
	
	results[1] = complexOperation(a, b, '-');
	
	results[2] = complexOperation(a, b, '*');
	
	results[3] = complexOperation(a, b, '/');
	
	printComplex(results);

	return 0;
}
