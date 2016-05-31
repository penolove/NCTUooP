#include <iostream>
#include <vector>
#include "Complex.h"
#include <stdlib.h>
#include <algorithm>
using std::cout; using std::endl;
using std::vector;
int main()
{
	int n ;
	cin>>n;
	//double real=[1.6,1.6,7.5,6.4,3.8];
	vector<Complex> vec(n);
	Complex x;
	for (int i = 0; i < vec.size(); i++){
		x.assign((rand()%1000)/10.0,(rand()%1000/10.0));
		vec[i]=x;
		cout << vec[i] << " ";
	}
	cout<<endl;

	n=vec[0]<vec[1];
	cout<<n<<endl;
	sort(vec.begin(), vec.end());
	
	for (int i = 0; i < vec.size(); i++){
		cout << vec[i] << " ";
	}
 	cout<<endl;	
	
	return 0;
}
