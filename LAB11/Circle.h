#include "Point2D.h"
#include "Shape.h"
#ifndef CIRCLE_H
#define CIRCLE_H
class Circle: public Shape
{
	public:
		Circle(Point2D x,double radius);
		void draw();
		double area();
		
	private:
			Point2D center;
			double radius;
};
#endif
