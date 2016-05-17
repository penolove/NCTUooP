#include <iostream>
#include "Point2D.h"
#include <math.h>
using namespace std;
void Point2D::display() const{
     cout<<x<<","<<y;
}

double Point2D::distance(Point2D n1){
	double a;
//	vertices[1].display();
//	cout<<"\n";
	a = sqrt(pow(n1.x-x, 2) + pow(n1.y-y, 2));
}

int Point2D::innerproduct(Point2D n1){
	return (n1.x*x+n1.y*y);
}
Point2D Point2D::vectormize(Point2D n1){
	Point2D c(x-n1.x,y-n1.y);
	return c;
}
