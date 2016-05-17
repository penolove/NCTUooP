#include <iostream>
using namespace std;
/* abstract class Shape defined in lab11-3 */
/* general class Point2D defined in lab11-2 */
class Point2D
{
	public:
		Point2D(){
			x = new int (0);
			y = new int (0);
			cout << "New X and Y" << endl;
		}
		Point2D(int n1,int n2){
			x = new int (n1);
			y = new int (n2);
		}
		void display(){
			cout<<*x<<","<<*y;
		}
		~Point2D()
		{
		//	delete x;
	//		delete y;
			cout << "Delete X and Y" << endl;
		}
	private:
		int *x;
		int *y;
};


class Shape
{
	public:
		Shape(int y){
			color=y;
		}
		virtual void draw() = 0;
		virtual bool is_closed() = 0;
		virtual ~Shape(){}
		void setColor(int y){
			color=y;
		}
	protected:
		int color;
};


class Circle: public Shape
{
	public:
		// constructor of Circle.
		Circle(Point2D x,int r,int y):Shape(y){
			center=x;
			radius=r;
		}
		void draw(){
			cout<<"center : ";     
			center.display();
			cout<<endl;
			cout<<"radius : "<<radius<<endl;
			cout<<"color :"<<color<<endl;
		};
		bool is_closed() { return true; }
	private:
		Point2D center;
		double radius;
};

int main()
{
	Point2D pt(3,4);
	Circle c(pt,5,255);
//	pt.display();
	c.draw();
	return 0;
}
