#include <iostream>
using namespace std;

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
		void setPoint2D(int n1,int n2){
			*x=n1;
			*y=n2;
		}
		void setPoint2D(Point2D qq){
			*x=*qq.x;
			*y=*qq.y;
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


class Polygon: public Shape
{
	public:
		Polygon(int color=0):Shape(color){};
		//Polygon(int color):Shape(color){};
		bool is_closed() { return true; }
};
class Triangle: public Polygon
{
	public:
		// constructor for Triangle
		Triangle(Point2D *x,int y){
			vertices=new Point2D[3];
			vertices[0].setPoint2D(x[0]);
			vertices[1].setPoint2D(x[1]);
			vertices[2].setPoint2D(x[2]);
			
			color=y;
		}
		bool is_closed() { return true; }
	//	~Triangle() { delete [] vertices; }
		void draw(){
			cout<<"color : "<<color<<endl;
			cout<<"Vertices : ";
			for(int i=0;i<3;i++){
				vertices[i].display();
				cout<<"\n";
			}
		};
	private:
		Point2D *vertices;
};
int main()
{
	Point2D *vec = new Point2D[3];
	vec[0].setPoint2D(1,1);
	vec[1].setPoint2D(6,1);
	vec[2].setPoint2D(1,8);
	Triangle t(vec,255);
	delete []vec;
	t.draw();
	return 0;
}
