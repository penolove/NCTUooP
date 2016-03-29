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
	data =new int[length];
	if(a[0]=='-'){
		sign=0;
		length-=1;
		for (int i=0;i<length;i++){
			data[i]=a[i+1]-'0';
		}
	}else{
		sign=1;
		for (int i=0;i<length;i++){
			data[i]=a[i]-'0';
		}
	}
}

HugeInteger::HugeInteger(const HugeInteger &a){
	length=a.length;
	sign=a.sign;
	data =new int [length];
	for(int i=0;i<length;i++){
		data[(length-1)-i]=a.data[i];
	}
}




void HugeInteger::output(){
	if(sign==0){
		cout<<'-';
	}
	for(int i=0;i<length;i++){
		cout<<data[i];
	}
}


HugeInteger HugeInteger::add(HugeInteger a){
	HugeInteger temp(a);	
	int record=0;

	if(a.length<length){
		a.data=data;
		a.length=length;
		a.sign=sign;
		data=temp.data;
		length=temp.length;
		sign=temp.sign;
	}

	for(int i=0;i<length;i++){
		temp.data[i]=a.data[i]*a.sign+data[i]*sign;
	}
	for(int i=length;i<a.length;i++){
		temp.data[i]=a.data[i];
	}
	int extend=0;

	if(abs(temp.data[temp.length-1])>=10 ){
		extend=1;	
	}

	//serach sign of largest number 
	int oppo=0;
	while(oppo==0&&temp.length>0){
		if(temp.data[temp.length]>0){
			oppo=1;
		}else if (temp.data[temp.length<0]){
			oppo=-1;
		}
		temp.length--;
	}

	if(oppo!=0){		
		for(int i=0;i<temp.length;i++){
			if(temp.data[i]*oppo<0){
				temp.data[i]+=(10*oppo);
				temp.data[i+1]-=(1*oppo);
			}
		}		
	}else{
		HugeInteger temp4return;
		temp4return.length=1;
		temp4return.data= new int [1];
		temp4return.data[0]=1;
		temp4return.sign=1;
		return temp4return;
	}
	
	//clear the 0 header
	oppo=0;
	while(oppo==0&&temp.length>0){
		if(temp.data[temp.length]>0){
			oppo=1;
		}else if (temp.data[temp.length<0]){
			oppo=-1;
		}
		temp.length--;
	}

	HugeInteger temp4return();
	temp4return.length=temp.length;
	temp4return.data = new int[length];
	
	if(oppo==-1){
		temp4return.sign=0;
	}else{
		temp4return.sign=1;
	}

	for( int i=0;i<temp.length;i++){
		temp.data[i]*=oppo;
		temp4return=temp.data[i];
	}

}



