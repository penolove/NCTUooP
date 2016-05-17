
#ifndef Shape_H
#define Shape_H
class Shape
{
	public:
		virtual double area()=0;
		Shape(int n1=0){color=n1;}
	protected:
	int color;
};
#endif
