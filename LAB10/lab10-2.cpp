#include <iostream>
#include "Circle.h"
#include "Triangle.h"
using namespace std;

using namespace std;

class Circle_in_Triangle: public Circle, public Triangle
{
	public:
		Circle_in_Triangle(Point2D p,int radius,Point2D *vec):Circle(p,radius),Triangle(vec),Shape(0){
		}
		void area(){
			cout<<"circle area : "<<Circle::area();
			cout<<"Triangle area :"<<Triangle::area();
			cout<<"out of circle area:"<<Triangle::area()-Circle::area();
		}		
		void draw()
		{
			cout << "Circle's color: " << Circle::color << endl;
			cout << "Triangle's color: " << Triangle::color <<endl;
			cout << "Circle_in_Triangle's color: " << color <<endl;
			Circle::draw();
			cout<<endl;
			Triangle::draw();
			cout<<endl;
			cout<<"circle area : "<<Circle::area()<<endl;
			cout<<"Triangle area :"<<Triangle::area()<<endl;
			cout<<"out of circle area:"<<Triangle::area()-Circle::area()<<endl;
		}
};



int main()
{
	Point2D p(1,1);
	Point2D p1(3,1);
	Point2D p2(1,6);
	Point2D *vec = new Point2D [3];
	vec[0]=p;
	vec[1]=p1;
	vec[2]=p2;
	Circle_in_Triangle ct(p, 1, vec);
	ct.draw();
	return 0;
}
