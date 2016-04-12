#include <iostream>
#include "HugeInteger.h"
using namespace std;
int main(){
    HugeInteger n1( "10000000000000" ); // HugeInteger object n1
    HugeInteger n2( "9000000000000" );
    HugeInteger n4( 5 ); // HugeInteger object n4
    HugeInteger n5; // HugeInteger object n5
    // outputs the sum of n1 and n2
    n5 = n1.add( n2 );
    n1.output();
    cout << " + ";
    n2.output();
    cout << " = ";
    n5.output();
    cout << endl;
}

