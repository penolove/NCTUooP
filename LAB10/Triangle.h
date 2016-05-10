#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Point2D.h"
#include <iostream>
#include "Shape.h"
using namespace std;
class Triangle:virtual public Shape
{
	public:
		Triangle(Point2D *x){
			vertices=x;
		};
		~Triangle(){ delete [] vertices; }
		void draw();
		double area();
		
	private:
		Point2D *vertices;
};
#endif
