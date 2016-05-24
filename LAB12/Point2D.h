
#ifndef Point2D_H
#define Point2D_H
#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;

class Point2D
{
	private:
		int x;
		int y;
	public:
		Point2D(int i=0){
			x=i;
			y=i;
		};
		Point2D(int i,int j){
			x=i;
			y=j;
		};
		void operator += (Point2D ptd){
			x+=ptd.x;
			y+=ptd.y;
		}
		Point2D operator * (Point2D ptd){
			x*=ptd.x;
			y*=ptd.y;
			return Point2D(x,y);
		}
		void display(){
			cout<<"("<<x<<","<<y<<")";
		}
		void setx(int x1){
			x=x1;
		}
		void sety(int x1){
			y=x1;
		}
		int getx(){
			return x;
		}
		int gety(){
			return y;
		}
		friend ostream& operator<<(ostream& os, const Point2D& x);
};

ostream& operator<<(ostream& os, const Point2D&  ptd)
{
    os <<"(" <<ptd.x<<","<<ptd.y<<")";
    return os;
}
#endif
