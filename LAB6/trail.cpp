#include <iostream> 
#include <ctime> 
#include <string>
#include "Date.h"
using namespace std;
int main(){
    Date a(256,1999);
    a.printDDDYYYY();
    a.print();
    a.printMMDDYY();
    a.printMonthDDYYYY();
    Date b;
    b.printDDDYYYY();
    b.print();
    b.printMMDDYY();
    b.printMonthDDYYYY();
}
