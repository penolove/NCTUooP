#ifndef POINT2D_H
#define POINT2D_H

class Point2D
{
	public:
		Point2D(int n1=0,int n2=0){ x = n1; y = n2; }
		void display() const;
		double distance(Point2D n1);
		int innerproduct(Point2D n1);
		Point2D vectormize(Point2D n1);
		void set(Point2D n1){
			x=n1.x;
			y=n1.y;
		};
		void setPoint2D(int n1,int n2){
			x=n1;
			y=n2;
		}
		void setPoint2D(Point2D qq){
			x=qq.x;
			y=qq.y;
		}
	private:
			int x;
			int y;
};

#endif
