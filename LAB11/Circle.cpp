#include <iostream>
#include "Point2D.h"
#include "Circle.h"
#include "math.h"
using namespace std;

Circle::Circle(Point2D x,double y):Shape(5){
	center.set(x);
	radius=y;
}

void Circle::draw(){
	cout<<"Center : ";
	center.display();
	cout<<"Radius : ";
	cout<<radius;
}
double Circle::area(){
	return pow(radius,2)*3.14;
}
