#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <math.h>
using namespace std;
template <class T>
class Vector
{
	private:
		int len;
		T* vec;
	public:
		void display() const;
		Vector(int n,T x){
			len=n;
			vec= new T[n];
			for (int i = 0; i < n; i++){
				vec[i]=x;
			}
		};


		void operator += (Vector<T> x){
			for (int i = 0; i < len; i++){
				vec[i]+=x.vec[i];
			}
			//vec= vecx;*/
			//return Vector(lenn,vecx); 
		}

		Vector(int n,T* x){
			len=n;
			vec= new T[n];
			for (int i = 0; i < n; i++){
				vec[i]=x[i];
			}
		};
		template<class S>
			friend S dot (const Vector<S> &, const Vector<S> &);
};

template <class T>
void Vector<T>::display() const{
	for (int i = 0; i < len; i++){
		cout<<vec[i]<<" ";
	}
	cout<<"\n";
}

template<class S>
S dot (const Vector<S> &x1, const Vector<S> &x2){
	S temp=0;
	for (int i = 0; i < x1.len; i++){
		temp+=x1.vec[i]*x2.vec[i];
	}
	return temp;
}
#endif
