
#include <iostream>
#include "Point4D.h"
using namespace std;

void Point4D::display() {
     Point2D::display();
     cout<<","<<*z<<","<<*t;
}


