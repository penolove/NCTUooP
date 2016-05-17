#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Point2D.h"
#include <iostream>
#include "Shape.h"
using namespace std;
class Triangle: public Shape
{
	public:
		Triangle(Point2D *x):Shape(6){

			vertices=new Point2D[3];
			vertices[0].setPoint2D(x[0]);
			vertices[1].setPoint2D(x[1]);
			vertices[2].setPoint2D(x[2]);
			
			
		}
		~Triangle(){ delete [] vertices; }
		void draw();
		double area();
	private:
		Point2D *vertices;
};
#endif
