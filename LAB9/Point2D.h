// Point2D.h
#ifndef POINT2D_H
#define POINT2D_H
class Point2D
{
   public:
       /*
        Point2D() {
            x=new int;
            y=new int;
        }
        */
        Point2D(int n1=1,int n2=0){
            x=new int;
            y=new int;
            *x=n1;
            *y=n2;
        }
        void display() ;
   private:
   int *x;
   int *y;
};
#endif

