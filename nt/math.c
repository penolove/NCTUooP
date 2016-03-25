#include "math.h"

inline int myPow2(int num) {

		return num*num; 
} 

int myPow(int n, int p) {

		int r = 1; 
		int i;
		for(i = 0; i < p; i++) {

				r *= n;
		}

		return r; 
}
