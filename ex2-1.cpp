#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <sstream>
#include <stdio.h>

using namespace std;
#define SIZE 10


template <class T>
T selectsort(T value1[])
{	T chtemp;
	T temp;
	for(int i=0;i<SIZE;i++){
		temp=value1[i];
		int record=i;
		for(int j=i;j<SIZE;j++){
			if(value1[j]<temp){
				temp=value1[j];
				record=j;
			}
		}
		chtemp=value1[record];
		value1[record]=value1[i];
		value1[i]=chtemp;
		cout<<value1[i]<<" ";
	}
	cout<<"\n";
	
}

int main(void){
	double b[SIZE] = { 2.2, 9.9, 10.1, 1.1, 7.7, 3.3, 4.4, 5.5, 8.8, 6.6};
			 
	int a[SIZE] = { 2, 9, 10, 1, 7, 3, 4, 5, 8, 6 };

	selectsort(a);
	selectsort(b);
	return 0;
}

