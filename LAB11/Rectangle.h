#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Point2D.h"
#include <iostream>
#include "Shape.h"
using namespace std;
class Rectangle: public Shape
{
	public:
		Rectangle(Point2D *x){

			vertices=new Point2D[4];
			vertices[0].setPoint2D(x[0]);
			vertices[1].setPoint2D(x[1]);
			vertices[2].setPoint2D(x[2]);
			vertices[4].setPoint2D(x[4]);
			
		}
		~Rectangle(){ delete [] vertices; }
		void draw();
		double area();
	private:
		Point2D *vertices;
};
#endif
