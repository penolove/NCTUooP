
#include <iostream>
#include "math.h"
#include "Point2D.h"
#include "Triangle.h"
#include "Circle.h"
#include "Rectangle.h"

using namespace std;

int main()
{
	Point2D pt(3,4);
	Circle cir(pt, 5);
	Point2D *vec = new Point2D [3];
	vec[0].setPoint2D(1,1);
	vec[1].setPoint2D(1,6);
	vec[2].setPoint2D(8,1);
	Triangle tri(vec);
	
	   delete []vec;
	   vec = new Point2D [4];
	   vec[0].setPoint2D(1,1);
	   vec[1].setPoint2D(6,1);
	   vec[2].setPoint2D(6,6);
	   vec[3].setPoint2D(1,6);
	   Rectangle rect(vec);
	   delete [] vec;

	   Shape *collection[3];
	   collection[0] = &cir;
	   collection[1] = &tri;
	   collection[2] = &rect;
	   cout << "Area of Circle: " << collection[0]->area()
	   << endl;
	   cout << "Area of Triangle: " << collection[1]->area()
	   << endl;
	   cout << "Area of Rectangle: " << collection[2]->area()
	   << endl;
	return 0;
}
