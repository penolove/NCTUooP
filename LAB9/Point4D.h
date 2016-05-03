#ifndef POINT4D_H
#include "Point2D.h"
#define POINT4D_H
class Point4D:public Point2D
{
    public:
        Point4D(int n1=0,int n2=0,int n3=0,int n4=0):Point2D(n1,n2){
            z=new int;
            t=new int;
            *z=n3;
            *t=n4;
        };

        Point4D(const Point2D &p){
            z=new int;
            t=new int;
            *z=0;
            *t=0;
        }
        void display();
    private:
        int *z;
        int *t;
};
#endif

