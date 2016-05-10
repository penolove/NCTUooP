#include <iostream>
#include "Point2D.h"
#include "Triangle.h"
#include "math.h"
using namespace std;

void Triangle::draw(){
	cout<<"Vertices : \n";
	vertices[0].display();
	cout<<"\n";
	vertices[1].display();
	cout<<"\n";
	vertices[2].display();
	cout<<"\n";
	
}
double Triangle::area(){
	double x=vertices[0].distance(vertices[1]);
	double y=vertices[0].distance(vertices[2]);
	int in=vertices[0].vectormize(vertices[1]).innerproduct(vertices[0].vectormize(vertices[2]));
	double sin=sqrt(1-pow(in/x/y,2));
	//cout<<x;
	//cout<<
	return x*sin*y/2;
}
