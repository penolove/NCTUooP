#include <string>
#include <map>
#include <sstream>
#define PI 3.14159



inline double cirArea(double x){
	return PI*x*x;
}


using namespace std;

int main(void){
	cout<<"Enter the radius of the circle: ";
	double x;
	cin>>x;
	cout<<"The area of the circle is "<<cirArea(x)<<"\n";
	return 0;
}
