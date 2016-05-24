#include <iostream>
#include <iomanip>
#include <stdlib.h>     /* srand, rand */
using namespace std;

class Point2D
{
	private:
		int x;
		int y;
	public:
		Point2D(){
			x=0;
			y=0;
		};
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
			// add any member if necessary
};

template<class T>
T* new1D(int n, int k)
{
	T *vec = new T [n];
	for (int i = 0; i < n; i++)
		vec[i] = (T)k;
	return vec;
}
template<>
Point2D* new1D(int n, int k)
{
	Point2D *vec = new Point2D[n];
	for (int i = 0; i < n; i++){
		vec[i] = Point2D();
		//vec[i].display();
		//cout<<" "; 
	}
	return vec;
}

template<class T>
void rand1D(T *vec, int n)
{
	for (int i = 0; i < n; i++){
		vec[i] = (T)rand()%10;
		//		cout<<rand()%10<<" ";
	}
	//	cout<<"\n";
}

template<>
void rand1D(double *vec, int n)
{
	for (int i = 0; i < n; i++){
		vec[i] = (double)(rand()%1000)/100;
		//		cout<<vec[i]<<" ";
	}
	//	cout<<"\n";
}

template<>
void rand1D(Point2D *vec, int n)
{
	for (int i = 0; i < n; i++){
		vec[i].setx((rand()%9));
		vec[i].sety((rand()%9));
		
		//		cout<<vec[i]<<" ";
	}
	//	cout<<"\n";
}
template<>
void rand1D(char *vec, int n)
{
	for (int i = 0; i < n; i++){
		vec[i] = (char)(rand()%26)+97;
		//		cout<<vec[i]<<" ";
	}
	//	cout<<"\n";
}


template<class T>
void display1D(T *vec, int n)
{
	for (int i = 0; i < n; i++){
		//	vec[i] = (char)(rand()%26)+97;
		cout<<vec[i]<<" ";
	}
	cout<<"\n";
}


template<>
void display1D(Point2D *vec, int n)
{
	for (int i = 0; i < n; i++){
		//	vec[i] = (char)(rand()%26)+97;
		vec[i].display();
		cout<<" ";
	}
	cout<<"\n";
}
template<class T>
void sort1D(T *vec, int n)
{
	T x=0;
	T *vecx = new T [n];

	for (int j = 0; j < n; j++){
		int record=0;
		x=0;
		for (int i = 0; i < n; i++){
			if(vec[i]>=x){
				x=vec[i];
				record=i;
			}
		}
		vecx[n-j-1]=x;
		vec[record]=0;
	//	cout<<x<<" ";
	}
	for (int j = n-1; j >= 0; j--){
		vec[j]=vecx[n-1-j];
	}	
	delete [] vecx;
	//cout<<"\n";
}
template<>
void sort1D(char *vec, int n)
{
	char x='a';
	char *vecx = new char [n];

	for (int j = 0; j < n; j++){
		int record=0;
		x='a';
		for (int i = 0; i < n; i++){
			if(vec[i]>=x){
				x=vec[i];
				record=i;
			}
		}
		vecx[n-j-1]=x;
		vec[record]=0;
	}
	for (int j = n-1; j >= 0; j--){
		vec[j]=vecx[j];
	}	
	delete [] vecx;
}

template<>
void sort1D(Point2D *vec, int n)
{
	int x=0;
	int y=0;
	Point2D *vecx = new Point2D[n];

	for (int j = 0; j < n; j++){
		int record=0;
		x=0;
		y=0;
		for (int i = 0; i < n; i++){
			if(vec[i].getx()>x || ( vec[i].getx()==x&& vec[i].gety()>y ) ){
				x=vec[i].getx();
				y=vec[i].gety();
				record=i;
			}
		}
		vecx[n-j-1]=vec[record];
		vec[record].setx(0);
	//	cout<<x<<" ";
	}
	for (int j = n-1; j >= 0; j--){
		vec[j]=vecx[j];
	}	
	delete [] vecx;
	//cout<<"\n";
}
	template<class T>
void analysis(int n, int k = 0)
{
	T *vec = new1D<T> (n, k);
	rand1D<T>(vec,n);
	// for int 1~10, for double 0.00~10.00, for char a~z,
	// // for Point2D x: 0~9 y:0~9
	display1D<T>(vec,n);
	sort1D<T>(vec,n);
	display1D<T>(vec,n);
}
int main()
{
	int n;
	cout << "Enter n: ";
	cin >> n;
	srand(1);
	analysis<int>(n);
	analysis<double>(n);
	analysis<char>(n);
	analysis<Point2D>(n);
	return 0;
}
