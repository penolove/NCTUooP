#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;


int char_len(char *x){
    int temp=0; 
    while(*(x+temp)!='\0'){
         temp++;
    }
    return temp;
        
}


int stringCompare1(char x[],char y[]){
   if(char_len(x)==char_len(y)){
    for (int i=0;i<char_len(x)+1;i++)    
        if(x[i]!=y[i]){
            return -1;
        }
    return 1;
   }else{
     return 0;
   }  
}

int stringCompare2(char *x,char *y){
   if(char_len(x)==char_len(y)){
    for (int i=0;i<char_len(x)+1;i++)    
        if(*(x+i)!=*(y+i)){
            return -1;
        }
    return 1;
   }else{
     return 0;
   }  
}

int main (void){
     char string1[1000] ;

     char string2[1000] ;
     cout<<"Enter first string : ";
     cin>> string1;
     cout<<"\n";

     cout<<"Enter second string : ";
     cin>> string2;
     cout<<"\n";
    
     cout<<"";
cout << "The value returned from stringCompare1( \"" << string1
    << "\", \"" << string2 << "\" ) is "
    << stringCompare1(string1,string2) 
    << "\nThe value returned from stringCompare2( \"" << string1
    << "\", \"" << string2 << "\" ) is "
    << stringCompare2(string1,string2)<<"\n";
    // /* Write a function call for stringCompare2 */ << '\n';


}
