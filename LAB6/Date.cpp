#include <iostream> 
#include <ctime> 
#include <string>
#include "Date.h"
#include <iomanip>

using namespace std;
Date::Date(){
    tm *year1; 
    time_t t; 
    t=time(0); 
    year1=localtime(&t);
    year=(year1 ->tm_year+1900);//返回的是今年减1900,所以要加上190
    month=(year1 ->tm_mon+1);//因为Month (0 – 11; January = 0),所以要加1 
    day=(year1 ->tm_mday);
};


Date::Date( int x, int y){
    int a[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    month=1;
    year=y;
    if(isLeapYear()){
        a[1]+=1;
    }
    while(x>a[month-1]){
        x-=a[month-1];
        month++;
    }
    day=x;
};


Date::Date( int month , int day, int year){
    this->day=day;
    this->month=month;
    this->year=year;         
}; // constructor using dd/mm/yy format

Date::Date( string month, int day, int year){
     string a[12]={"January", "February", "March", "April", "May", "June", "July","August", "September", "October", "November", "December"};
     this->day=day;
     this->year=year;
     this->month=1;
     while(month.compare(a[this->month-1])!=0&&this->month<=12){
        this->month++;       
     }
}; // constructor using Month dd, yyyy format

void Date::print() const{
    cout<<month<<"/"<<day<<"/"<<year<<endl;
};



void Date::printDDDYYYY() const{
    int a[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int d=0;
    if(isLeapYear()){
        a[1]+=1;
    }
    for(int i=0;i<month-1;i++){
        d+=a[i];
    }
    d+=day;
    cout<< std::setfill('0') << std::setw(3) << d<<" ";
    cout<< std::setfill('0') << std::setw(4)<<year<<endl;
}; // print date in ddd yyyy format

bool Date::isLeapYear() const{
    return (year%4==0&&(year%100!=0||year%400==0));
}; // indicates whether date is in a leap year



void Date::printMMDDYY() const{
     
    cout<< std::setfill('0') << std::setw(2)<<month<<"/";
    cout<< std::setfill('0') << std::setw(2)<<day<<"/";
    cout<< std::setfill('0') << std::setw(2)<<year%100<<"\n";
}; // print date in mm/dd/yy format


void Date::printMonthDDYYYY() const{
    //cout<<"now month"<<month<<"\n";
     string a[12]={"January", "February", "March", "April", "May", "June", "July","August", "September", "October", "November", "December"};
    cout<<a[(month-1)]<<" "<<day<<", "<<year<<"\n";
}; // print date in Month dd, yyyy format


Date::~Date(){
    cout<<"De ni me ";
    print();
}
