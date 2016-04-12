#include <iostream>
#include <string>
#include <cstdlib>
#include "HugeInteger.h"

using namespace std;

HugeInteger::HugeInteger(){
    length=1;
    sign=0;
    data=new int[length];
    data[0]=0;
}

HugeInteger::HugeInteger(int a){
    length=0;
    if(a<0){
        a=a*(-1);
        sign=0;
    }else{
        sign=1;
    }
    int temp=a;
    if(temp==0){
        length=1;
        sign=0;
        data=new int[length];
        data[0]=0;
    }
    while(temp>0){
        length++;
        temp/=10;
    }
    data =new int[length];
    for(int i=0;i<length;i++){
        data[i]=a%10;
        a/=10;
    }
}

HugeInteger::HugeInteger(string a){
    length=a.length();
    if(a[0]=='-'){
        sign=0;
        length-=1;
        data =new int[length];
        for (int i=0;i<length;i++){
            data[(length-1)-i]=a[i+1]-'0';
        }
    }else{
        sign=1;
        data =new int[length];
        for (int i=0;i<length;i++){
            data[(length-1)-i]=a[i]-'0';
        }
    }
}

HugeInteger::HugeInteger(const HugeInteger &a){
    length=a.length;
    sign=a.sign;
    data =new int [length];
    for(int i=0;i<length;i++){
        data[i]=a.data[i];
    }
}




void HugeInteger::output(){
    if(sign==0){
        cout<<'-';
    }
    for(int i=length-1;i>=0;i--){
        cout<<data[i];
    }
}


HugeInteger HugeInteger::add(HugeInteger a){
    HugeInteger temp(a);
    HugeInteger aa(a);
    HugeInteger b;
    int record=0;

    //copy a b avoid to change original object
    b.data=data;
    b.sign=sign;
    b.length=length;
/*
    cout<<"phase1"<<endl;
    cout<<"temp length :"<<temp.length<<endl;
    temp.output();
    cout<<endl;
*/  
    //since we want to make swap thus need to create b;
    if(aa.length<b.length){
        aa.data=b.data;
        aa.length=b.length;
        aa.sign=b.sign;
        b.data=temp.data;
        b.length=temp.length;
        b.sign=temp.sign;
    }


    //make sure temp and a/b were not binded;
    temp.sign=aa.sign;
    temp.length=aa.length;
    int * datatemp;
    datatemp=new int [temp.length];
    for(int i=0;i<aa.length;i++){
        datatemp[i]=aa.data[i];
    }
    temp.data=datatemp;

/*
    cout<<"phase1.5"<<endl;
    cout<<"temp length :"<<temp.length<<endl;
    temp.output();
    cout<<endl;
*/


    int asign=aa.sign==0?-1:1;
    int bsign=b.sign==0?-1:1;

    for(int i=0;i<b.length;i++){
        temp.data[i]=aa.data[i]*asign+b.data[i]*bsign;
    }
    for(int i=b.length;i<a.length;i++){
        temp.data[i]=aa.data[i]*asign;
    }
/*
    cout<<"phase2"<<endl;
    cout<<"temp length :"<<temp.length<<endl;
    temp.output();
    cout<<endl;
*/

    //serach sign of largest number
    //since the sign of number
    //will be the same as largest digit
    int oppo=0;
    int first=0;
    while(oppo==0&&temp.length>0){
        if(temp.data[temp.length-1]>0){
            oppo=1;
            break;
        }else if (temp.data[temp.length-1]<0){
            oppo=-1;
            break;
        }
        if(first!=0){
            temp.length--;
        }
        first++;
    }
/*
    cout<<"phase3"<<endl;
    cout<<"temp length :"<<temp.length<<endl;
    temp.output();
    cout<<endl;
*/



    //now deal with the carry problem
    if(oppo!=0){		
        for(int i=0;i<temp.length;i++){
            //if not the same as largest number
            if(temp.data[i]*oppo<0){
                temp.data[i]+=(10*oppo);
                temp.data[i+1]-=(1*oppo);
            }
            //if more than ten -> carry!!
            if(temp.data[i]*oppo>=10){
                //if the first one
                if(i==(temp.length-1)){
                    if(abs(temp.data[temp.length-1])>=10 ){
                        int firstTerm=temp.data[length-1];
                        temp.length++;
                        int * datatemp;
                        datatemp=new int [temp.length];
                        for(int i=0;i<temp.length-1;i++){
                            datatemp[i]=temp.data[i];
                        }
                        delete temp.data;
                        temp.data=datatemp;
                        temp.data[temp.length-2]%=10;
                        temp.data[temp.length-1]=1*oppo;
                    }
                }else{
                    temp.data[i]-=(10*oppo);
                    temp.data[i+1]+=(1*oppo);
                }
            }
        }		
    }else{
        //zero boy
        HugeInteger temp4return;
        temp4return.length=1;
        temp4return.data= new int [1];
        temp4return.data[0]=0;
        temp4return.sign=1;
        return temp4return;
    }
/*
    cout<<"phase3.5"<<endl;
    cout<<"temp length :"<<temp.length<<endl;
    temp.output();
    cout<<endl;
*/
    //clear the 0 header
    oppo=0;
    first=0;
    while(oppo==0&&temp.length>0){
        if(temp.data[temp.length-1]>0){
            oppo=1;
            break;
        }else if (temp.data[temp.length-1]<0){
            oppo=-1;
            break;
        }
        if(first!=0){
            temp.length--;
        }
        first++;
    }
/*
    cout<<"phase4"<<endl;
    cout<<"temp length :"<<temp.length<<endl;
    temp.output();
    cout<<endl;
*/
    HugeInteger temp4return;
    temp4return.length=temp.length;
    temp4return.data = new int[length];

    if(oppo==(-1)){
        temp4return.sign=0;
    }else{
        temp4return.sign=1;
    }

    for( int i=0;i<temp.length;i++){
        temp.data[i]*=oppo;
        temp4return.data[i]=temp.data[i];
    }
/*
    cout<<"phase5"<<endl;
    cout<<"temp length :"<<temp.length<<endl;
    temp.output();
    cout<<endl;
*/

    return temp4return;
}



