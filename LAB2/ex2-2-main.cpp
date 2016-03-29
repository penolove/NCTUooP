#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <sstream>
#include <stdio.h>
#include "ex2-2.h"

using namespace std;
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
