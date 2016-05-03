#include <iostream>
#include "Point4D.h"
using std::cout;
using std::endl;
int main()
{
    cout<<"fuck world"; 
    Point2D pt1(1,2);
    Point2D pt2(3,4);
    pt1.display(); cout << endl;
    pt2.display(); cout << endl;
    pt2 = pt1;
    Point2D pt3(pt1);
    cout<<"now I Pt3"<<endl;
    pt3.display();
    cout<<endl<<"now I fuck Pt3"<<endl;
    pt2.display(); cout << endl;
    Point4D pt4(5,6,7,8);
    pt4.display(); cout << endl;
    pt2 = pt4;
    pt2.display(); cout << endl;
    pt4 = pt1;
    //pt4 could be (1,2,7,8) or (1,2,0,0)
    pt4.display(); cout << endl;
    return 0;
}

