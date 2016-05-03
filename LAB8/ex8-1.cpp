#include <iostream>
using namespace std;

int char2int(char a[]){
    //cout<<"--------now in function-------"<<endl;
    int idx=0;
    int sum=0;
     while(a[idx]!='\0'){
     //   cout<<a[idx]<<endl;
         sum*=10;
         sum+=a[idx]-'0';
         idx++;
     }
    //cout<<"--------now out function-------"<<endl;
    return sum;
}




int main(int argc, char *argv[]){
    int temp=1;
    int sum=0;

    if(argv[1][0]=='-'){
         temp=-1;
         sum+=char2int(argv[1]+1)*temp;
    }else{
         sum+=char2int(argv[1]);
         cout<<sum<<endl;
    }

     for(int i=2; i<argc ;i++){
         if(argv[i][0]=='+'){
             temp =1;
         }else if(argv[i][0]=='-'){
             temp=-1;
             
         }else{
            sum+=char2int(argv[i])*temp;
//            cout<<char2int(argv[i])<<endl;
         }

       // cout<<sum<<endl;
     }
    cout<<"anwser: "<<sum<<endl;
}
